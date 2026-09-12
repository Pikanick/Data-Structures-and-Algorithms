// Regression test for the indexed-heap PQ. Exercises paths the original
// PQdemo.cpp specifically avoided (it only ever tested a single-swap
// priority decrease and never called deleteMin() -- both were disabled
// in commented-out blocks). Those paths turned out to hide real bugs:
// deleteMin() corrupted the AVL index tree via a dangling reference,
// the batch constructor never actually heapified (it happened to work
// only because the demo's priorities were pre-sorted), insert() had an
// off-by-one array index and never restored heap order, and a few
// functions fell off the end without returning a value.
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <random>
#include "PQ.h"

using namespace std;

int main()
{
    // --- Empty-queue behavior ---
    PQ<int> empty;
    assert(empty.isEmpty());
    assert(empty.size() == 0);
    bool threw = false;
    try { empty.deleteMin(); } catch (UnderflowException&) { threw = true; }
    assert(threw && "deleteMin() on an empty PQ should throw UnderflowException");
    threw = false;
    try { empty.findMin(); } catch (UnderflowException&) { threw = true; }
    assert(threw && "findMin() on an empty PQ should throw UnderflowException");
    cout << "Empty-queue checks: OK" << endl;

    // --- Batch constructor must heapify arbitrary (non-sorted) priorities ---
    mt19937 rng(12345);
    const int N = 200;
    vector<int> tasks(N), priorities(N);
    vector<int> shuffledPriorities(N);
    for (int i = 0; i < N; i++) { tasks[i] = i; shuffledPriorities[i] = i; }
    shuffle(shuffledPriorities.begin(), shuffledPriorities.end(), rng);

    PQ<int> pq(tasks, shuffledPriorities);
    assert(pq.size() == N);
    assert(!pq.isEmpty());

    // deleteMin() N times must come out in non-decreasing priority order,
    // and must return every task ID exactly once.
    vector<bool> seen(N, false);
    int lastPriority = -1;
    // We can't read priority directly off deleteMin()'s return (just the
    // task ID), so cross-check against the known task->priority mapping.
    vector<int> priorityOf(N);
    for (int i = 0; i < N; i++) priorityOf[tasks[i]] = shuffledPriorities[i];

    for (int i = 0; i < N; i++)
    {
        int taskID = pq.deleteMin();
        assert(taskID >= 0 && taskID < N);
        assert(!seen[taskID] && "deleteMin() returned the same task twice");
        seen[taskID] = true;
        int p = priorityOf[taskID];
        assert(p >= lastPriority && "deleteMin() came out of priority order");
        lastPriority = p;
    }
    for (int i = 0; i < N; i++) assert(seen[i] && "deleteMin() never returned some task");
    assert(pq.isEmpty());
    cout << "Batch constructor + full deleteMin() drain (heap order across " << N << " random priorities): OK" << endl;

    // --- insert() one at a time, with random priorities, must also
    //     maintain heap order (the fixed off-by-one + percolateUp) ---
    PQ<int> pq2;
    vector<int> ids(N);
    for (int i = 0; i < N; i++) ids[i] = i;
    vector<int> insertPriorities(N);
    for (int i = 0; i < N; i++) insertPriorities[i] = i;
    shuffle(insertPriorities.begin(), insertPriorities.end(), rng);
    for (int i = 0; i < N; i++) pq2.insert(ids[i], insertPriorities[i]);
    assert(pq2.size() == N);

    vector<int> priorityOf2(N);
    for (int i = 0; i < N; i++) priorityOf2[ids[i]] = insertPriorities[i];
    lastPriority = -1;
    for (int i = 0; i < N; i++)
    {
        int taskID = pq2.deleteMin();
        int p = priorityOf2[taskID];
        assert(p >= lastPriority && "insert()-built heap came out of order");
        lastPriority = p;
    }
    cout << "One-at-a-time insert() + deleteMin() ordering: OK" << endl;

    // --- updatePriority(): both a decrease (percolateUp) and an increase
    //     (percolateDown, the path the original demo never exercised) ---
    PQ<int> pq3(tasks, priorities); // priorities[i] == i, already sorted
    pq3.updatePriority(199, -1);    // was last, now should be the new min
    assert(pq3.findMin().TaskID == 199);

    pq3.updatePriority(0, 1000);    // was first (now displaced), push it to the back
    int countSeen = 0;
    while (!pq3.isEmpty())
    {
        int t = pq3.deleteMin();
        countSeen++;
        if (t == 0) { assert(countSeen == N && "task 0 should now come out last"); }
    }
    assert(countSeen == N);
    cout << "updatePriority() decrease + increase: OK" << endl;

    // --- updatePriority() on a task not yet in the queue must insert it,
    //     per the documented contract ---
    PQ<int> pq4;
    pq4.insert(1, 10);
    pq4.insert(2, 20);
    pq4.updatePriority(3, 5); // 3 isn't in the queue yet
    assert(pq4.size() == 3);
    assert(pq4.deleteMin() == 3);
    cout << "updatePriority() on an absent task ID inserts it: OK" << endl;

    // --- makeEmpty() ---
    pq2.makeEmpty();
    assert(pq2.isEmpty());
    assert(pq2.size() == 0);
    cout << "makeEmpty(): OK" << endl;

    cout << "PQTest: ALL CHECKS PASSED" << endl;
    return 0;
}
