#include <algorithm>
#include <iostream> 
#include <vector>
#include "AvlTree2.h"
#include "heap2.h"
using namespace std;

#ifndef PQ_H
#define PQ_H

// PQ class
//
// Template parameter: ID
// Constructors:
// PQ --> constructs a new empty queue
// PQ( tasks, priorities ) --> constructs a new queue with a given set of task IDs and priorities 
// ******************PUBLIC OPERATIONS*********************
// void insert( x, p )       --> Insert task ID x with priority p 
// ID findMin( )  --> Return a task ID with smallest priority, without removing it 
// ID deleteMin( )   --> Remove and return a task ID with smallest priority 
// void updatePriority( x, p )   --> Changes priority of ID x to p (if x not in PQ, inserts x);
// bool isEmpty( )   --> Return true if empty; else false
// int size() --> return the number of task IDs in the queue 
// void makeEmpty( )  --> Remove all task IDs (and their priorities)
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class PQ // heap tree implemented in an array. each array index contains a heapnode struct that points 
{
    public:
    BinaryHeap<int> Heap;
    AvlTree<int> AVLTHeap;
    // Constructor
    // Initializes a new empty PQ
    PQ() : root{ nullptr } {}
    
    // PQ(int capacity = 100 ) 
    //   { 
    //     Heap.reserve(capacity);
    //     HeapTaskIDs.reserve(capacity);
    //     HeapPriorities.reserve(capacity);
   
    //  }
    
    // PQ( const vector<Comparable> & items) //: root{ nullptr }
    // {
    //     Heap.reserve(items.size());
    //     for (int i = 1;i<=items.size(); i++)
    //     {
    //         Heap.push_back(items[i]);
    //     }
    //    // root = clone( rhs.root );
    // }

    // Constructor
    // Initializes a new PQ with a given set of tasks IDs and priorities  
    //      priority[i] is the priority for ID task[i] 
    PQ( const std::vector<Comparable> & tasks, const std::vector<int> & priorities2 ) 
    {
        int n = static_cast<int>(tasks.size());
        Heap.priorities.reserve(n);
        Heap.pointers.reserve(n);

        for (int i = 0; i < n; i++)
        {
            Heap.priorities.push_back(priorities2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            Heap.pointers.push_back(AVLTHeap.insert( tasks[i], i ));
        }

        // The arrays above are in *input* order, which is only a valid
        // min-heap by coincidence (e.g. if priorities2 happens to already
        // be sorted, as in the demo). Heapify bottom-up so findMin()/
        // deleteMin() are correct for arbitrary priorities too. This also
        // leaves every node's heapindex matching its post-heapify
        // position, since percolateDown() keeps that in sync on each swap.
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            Heap.percolateDown(i);
        }
    }		

    // Emptiness check 
    bool isEmpty( ) const // Return true if the PQ is empty, otherwise false.
    {
        //AVLTHeap.isEmpty&&
        return Heap.isEmpty();
    }

    // Deletes and Returns a task ID with minimum priority
    //    Throws exception if queue is empty
    Comparable deleteMin() //Remove and return the object with smallest priority.
    {
        // Was: passed Heap.pointers.at(0) (a slot in the heap's own array)
        // to AVLTHeap.deleteMin(AvlNode*&), which only correctly unlinks a
        // node from the AVL tree if the reference it's given *is* that
        // node's actual parent-link inside the tree. Heap.pointers[0] is
        // just a separate alias copy of the same address -- reassigning
        // it never touched the real link (root, or some other node's
        // ->left/->right) that the AVL tree itself uses to reach this
        // node, leaving the tree with a dangling pointer to freed memory.
        // AVLTHeap.remove(taskID) is the tree's own by-key removal, which
        // starts at `root` and correctly updates parent links throughout
        // the recursion, so use that instead.
        if (Heap.isEmpty())
        {
            throw UnderflowException{ };
        }
        Comparable minTaskID = Heap.pointers.at(0)->TaskID;
        Heap.deleteMin();
        AVLTHeap.remove(minTaskID);
        return minTaskID;
    }

    // Returns an ID with minimum priority without removing it
    //     Throws exception if queue is empty
    const AvlTree<int>::AvlNode & findMin() const //Return (a reference to) the object with the smallest priority.
    {
        const AvlTree<int>::AvlNode & x=Heap.findMin();
        return x;
        //return  Heap.priorities.findMin();
    }

    // Insert ID x with priority p.
    void insert( const Comparable & x, int p )
    {
        // Was: pushed onto Heap.priorities first, then used its *new*
        // size (already counting the just-added element) as the array
        // index for the AVL side -- off by one, since the element actually
        // lands at size()-1. Delegates to Heap.insert() instead, which
        // pushes both parallel arrays together, computes the index once,
        // and percolates up to restore heap order (which this never did
        // either).
        int idx = static_cast<int>(Heap.priorities.size());
        AvlTree<int>::AvlNode * node = AVLTHeap.insert( x, idx );
        Heap.insert( node, p );
    }

    
    // Update the priority of ID x to p
    //    Inserts x with p if x is not already in the queue
    void updatePriority( const Comparable & x, int p ) 
    {
        int oldindex = AVLTHeap.find(x);
        if (oldindex < 0)
        {
            // Not currently in the queue: the documented contract is to
            // insert it instead (the old code assumed x was always
            // already present, and fed find()'s undefined "not found"
            // return value straight into an array index).
            insert(x, p);
            return;
        }
        int newindex = Heap.updatePriority(oldindex, p);
        AVLTHeap.updatePriority( Heap.pointers[newindex], x, newindex);
    }

    // Return the number of task IDs in the queue
    int size() const // Return the number of objects in the PQ.
    {
        return Heap.size();
    }

    // Delete all IDs from the PQ
    void makeEmpty( ) //Remove all items from the PQ.
    {
        AVLTHeap.makeEmpty();
        Heap.makeEmpty();
    }
    
    void DisplayPQ( ) //Remove all items from the PQ.
    {
        cout << "Elements in the Heap are the following: "<<endl;
        for (int i = 0; i<Heap.priorities.size(); i++)
        {
            cout<<"Task ID: "<<(Heap.pointers[i])->TaskID<<", Priority: "<<Heap.priorities[i]<<endl;     
        }

        cout<<endl;
        AVLTHeap.displayLinks();
    }


    // PQ( PQ && rhs ) : root{ rhs.root }
    // {
    //     rhs.root = nullptr;
    // }
    
    ~PQ( )
    {
        makeEmpty( );
        //cout<<"Deconstructor"<<endl;
    }

    /**
     * Deep copy.
     */
    // PQ & operator=( const PQ & rhs )
    // {
    //     PQ copy = rhs;
    //     std::swap( *this, copy );
    //     return *this;
    // }
        
    /**
     * Move.
     */
    // PQ & operator=( PQ && rhs )
    // {
    //     std::swap( root, rhs.root );
        
    //     return *this;
    // }
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    // const Comparable & findMin( ) const
    // {
    //     if( isEmpty( ) )
    //         throw UnderflowException{ };
    //     return findMin( root )->element;
    // }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    // const Comparable & findMax( ) const
    // {
    //     if( isEmpty( ) )
    //         throw UnderflowException{ };
    //     return findMax( root )->element;
    // }

    /**
     * Returns true if x is found in the tree.
     */
    // bool contains( const Comparable & x ) const
    // {
    //     return contains( x, root );
    // }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    // bool isEmpty( ) const
    // {
    //     return root == nullptr;
    // }

    /**
     * Print the tree contents in sorted order.
     */
    // void printTree( ) const
    // {
    //     if( isEmpty( ) )
    //         cout << "Empty tree" << endl;
    //     else
    //         printTree( root );
    // }

    void displayLinks( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            //displayLinks( root, "",false, out );
            displayLinks( root, 0, out );
    }

    /**
     * Make the tree logically empty.
     */
    // void makeEmpty()
    // {
    //     Heap.clear();
    //     makeEmpty( root );

    // }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    // void insert( const Comparable & x )
    // {
    //     insert( x, root );
    // }

    struct PQNode
    {
        Comparable element;
        PQNode   *left;
        PQNode   *right;
        int       height;

        PQNode( const Comparable & ele, PQNode *lt, PQNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        PQNode( Comparable && ele, PQNode *lt, PQNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };

    PQNode *root;
    //vector<Comparable> Heap;
    
    // BinaryHeap HeapTaskIDs;
    // BinaryHeap HeapPriorities;
   
    // int currentSize; // Number of elements in heap

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    // void insert( const Comparable & x, PQNode * & t )
    // {
    //     if( t == nullptr )
    //         t = new PQNode{ x, nullptr, nullptr };
    //     else if( x < t->element )
    //         insert( x, t->left );
    //     else if( t->element < x )
    //         insert( x, t->right );
        
    //     balance( t );
    // } 
    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    // PQNode * findMin( PQNode *t ) const
    // {
    //     if( t == nullptr )
    //         return nullptr;
    //     if( t->left == nullptr )
    //         return t;
    //     return findMin( t->left );
    // }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    // PQNode * findMax( PQNode *t ) const
    // {
    //     if( t != nullptr )
    //         while( t->right != nullptr )
    //             t = t->right;
    //     return t;
    // }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    // bool contains( const Comparable & x, PQNode *t ) const
    // {
    //     if( t == nullptr )
    //         return false;
    //     else if( x < t->element )
    //         return contains( x, t->left );
    //     else if( t->element < x )
    //         return contains( x, t->right );
    //     else
    //         return true;    // Match
    // }

    /**
     * Internal method to make subtree empty.
     */
    // void makeEmpty( PQNode * & t )
    // {
    //     if( t != nullptr )
    //     {
    //         makeEmpty( t->left );
    //         makeEmpty( t->right );
    //         delete t;
    //     }
    //     t = nullptr;
    // }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    // void printTree( PQNode *t ) const
    // {
    //     if( t != nullptr )
    //     {
    //         printTree( t->left );
    //         cout << t->element << endl;
    //         printTree( t->right );
    //     }
    // }



    
     /**
     * Print the subtree structure rooted at t in sorted order.
     */
    // void displayLinks( const BinaryNode *t, const string& branch, bool Left, ostream & out ) const //preorder travesal 
    // {
    //     if( t != nullptr )
    //     { 
    //         cout<<branch;
    //         cout<<(Left?"|---" : "|___");
    //         out << t->element << endl;
    //         displayLinks( t->left, branch+(Left?"|   " : "    "),true, out );
    //         displayLinks( t->right, branch+(Left?"|   " : "    "),false, out );
    //     }
    // }
    
    // Print the subtree structure rooted at t in sorted order with address of root, left and right children.
    void displayLinks( PQNode *t, int depth, ostream & out ) const
    {
        
        const int SHIFT = 4 ;
        if( t != nullptr )
        {
            for( int i = 0 ; i < SHIFT*depth ; i++ )
            { 
                out << " " ; 
            }
            
            out << t->element << ") @:" << t << "   " << "L:" << t->left << "   " << "R:" << t->right << endl;
            displayLinks( t->left, depth+1, out );
            displayLinks( t->right, depth+1, out );
            //cout<<"hello"<<endl;
            
        }
    }

};

#endif
