#include <algorithm>
#include <iostream> 
#include <vector>
#include <math.h>
#include "AvlTree2.h"

using namespace std;

//Arr[(i-1)/2]	Returns the parent node
//Arr[(2*i)+1]	Returns the left child node
//Arr[(2*i)+2]	Returns the right child node

template <typename Comparable>
class BinaryHeap
{
    public:
    Comparable TaskID; //key
    AvlTree<int> *AVLT1;
    //AVLT1->AvlNode;
    AvlTree<int>::AvlNode *Avlpointer;
    vector<AvlTree<int>::AvlNode*> pointers; // The heap array
    vector<Comparable> priorities; // The heap array
    
    // BinaryHeap( ): TaskID(0), AVLT1(nullptr), Avlpointer(nullptr)
    // {

    // }
      BinaryHeap( ): TaskID(0), AVLT1(nullptr), Avlpointer(nullptr)
    {
          TaskID=0;
          AVLT1=nullptr; 
          Avlpointer=nullptr;
    }


    // BinaryHeap( int capacity )
    // {
    //     pointers.reserve(capacity); // The heap array
    //     priorities.reserve(capacity); // The heap array
    // // }
    // BinaryHeap( const vector<Comparable> & items )
    // {
        
    // }

    // void insert(AvlNode * & t, int p );
    // AvlNode * &  deleteMin();
    // AvlNode * &  findmin();
    // void updatePriority(int heapindex, int p);
    // bool isEmpty();
    // int size();
    // void makeEmpty( );
    
    
    // private:
    // int currentSize; // Number of elements in heap
  
    // int percolateDown( int hapindex );
    // int percolateUp( int hepindex );
    // void percolateDown( );
    // void percolateUp( );


    void insert(AvlTree<int>::AvlNode * & t, int p )// insert node pointer and priority into heap vector
    {
        pointers.push_back(t);
        priorities.push_back(p);
        int idx = static_cast<int>(priorities.size()) - 1;
        t->heapindex = idx;
        percolateUp(idx);
    }

    int percolateUp(int hepindex)
    {
        int v2,p2;
        v2=hepindex;//child
        p2=(v2-1)/2;//parent

        while(v2>0 && priorities.at(v2)<priorities.at(p2) )
        {
            swap(priorities.at(v2),priorities.at(p2));
            swap(pointers.at(v2),pointers.at(p2));
            pointers.at(v2)->heapindex = v2;
            pointers.at(p2)->heapindex = p2;
            v2=p2;
            p2=(v2-1)/2;//parent of the node's new position
        }
        return v2;

    }

    // Sift the element at index `hapindex` down until both children are
    // no smaller than it (or it has no children left).
    //
    // Rewritten from the original: it read priorities.at(2*v+2) (the
    // *right* child) guarded only by a check that the *left* child was in
    // bounds, so any node with a left child but no right child (any heap
    // with an even element count has at least one) threw
    // std::out_of_range. It also blocked on `cin>>k` after every swap and
    // printed on every step -- this is why deleteMin() below was never
    // actually exercised by the demo.
    int percolateDown(int hapindex)
    {
        int v = hapindex;

        while (true)
        {
            int left = 2 * v + 1;
            int right = 2 * v + 2;
            if (left >= static_cast<int>(priorities.size()))
            {
                break; // no children left
            }

            int smallerChild = left;
            if (right < static_cast<int>(priorities.size()) && priorities.at(right) < priorities.at(left))
            {
                smallerChild = right;
            }

            if (priorities.at(smallerChild) < priorities.at(v))
            {
                swap(priorities.at(smallerChild), priorities.at(v));
                swap(pointers.at(smallerChild), pointers.at(v));
                pointers.at(smallerChild)->heapindex = smallerChild;
                pointers.at(v)->heapindex = v;
                v = smallerChild;
            }
            else
            {
                break; // heap property restored
            }
        }
        return v;
    }

    // Remove the minimum (index 0). Was implemented as erase-from-front,
    // which shifts every remaining element down by one array position --
    // that relabels every node's parent/child relationships, not just the
    // root's, so a single percolateDown from the root cannot generally
    // restore heap order (it happened to work in the one hand-picked demo
    // case because that data was already fully sorted). Rewritten to the
    // standard approach: move the last element to the root and sift it
    // down, which is the transformation percolateDown is actually valid
    // for.
    void deleteMin()
    {
        if (pointers.empty())
        {
            throw UnderflowException{ };
        }
        pointers.at(0) = pointers.back();
        priorities.at(0) = priorities.back();
        pointers.pop_back();
        priorities.pop_back();
        if (!pointers.empty())
        {
            pointers.at(0)->heapindex = 0;
            percolateDown(0);
        }
    }

    AvlTree<int>::AvlNode & findMin() const// return highest (smallest) priority reference to object
    {
        if (pointers.empty())
        {
            throw UnderflowException{ };
        }
        return *(pointers.at(0));
    }

    bool isEmpty() const // check if heap vector is empty
    {
        return pointers.empty();
    }

    int size() const// return size of heap vectors
    {
        return static_cast<int>(pointers.size());
    }

    void makeEmpty()// clear vectors
    {
        pointers.clear();
        priorities.clear();
    }
    
    // Update the priority of ID x to p
    //    Inserts x with p if s not already in the queue
   // void updatePriority( const ID & x, int p ) 

    int updatePriority(int heapindex, int p)// change priority member, reorganize heap return new index
    {
        // Default to "didn't move" -- the old code left this uninitialized
        // (and returned garbage) whenever the new priority equalled the
        // old one, since neither branch below ran.
        int newindex = heapindex;
        int oldPriority = priorities.at(heapindex);
        priorities.at(heapindex) = p;

        if (oldPriority > p)
        {
            newindex = percolateUp(heapindex);
        }
        else if (oldPriority < p)
        {
            newindex = percolateDown(heapindex);
        }
        return newindex;
    }
};
