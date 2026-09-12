// Regression test for two bugs found while reviewing this assignment:
//   1. depth(x) had no `return` statement on its recursive call, so it
//      returned an undefined/garbage value instead of the actual depth.
//   2. height() dereferenced `root` without checking for an empty tree,
//      crashing instead of returning -1 (this codebase's convention for
//      an empty tree, matching AvlNode::height's ternary elsewhere).
// Covers both BinarySearchTree and AvlTree, since both classes had their
// own copies of depth()/height() with the same bugs.
#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

template <typename Tree>
void run(const char* name) {
    Tree t;

    // Empty tree: height() used to dereference a null root and crash.
    assert(t.height() == -1);

    int values[] = {50, 25, 75, 10, 30, 60, 90};
    for (int v : values) t.insert(v);

    // Known shape (BST/AVL insert order both give this exact tree for a
    // balanced input like this one): 50 at the root, 25/75 as its
    // children, and 10/30/60/90 as the four leaves underneath them.
    assert(t.height() == 2);
    assert(t.depth(50) == 0);
    assert(t.depth(25) == 1);
    assert(t.depth(75) == 1);
    assert(t.depth(10) == 2);
    assert(t.depth(30) == 2);
    assert(t.depth(60) == 2);
    assert(t.depth(90) == 2);

    cout << name << ": all assertions passed" << endl;
}

int main() {
    run<BinarySearchTree<int>>("BinarySearchTree");
    run<AvlTree<int>>("AvlTree");
    cout << "EdgeCaseTest: OK" << endl;
    return 0;
}
