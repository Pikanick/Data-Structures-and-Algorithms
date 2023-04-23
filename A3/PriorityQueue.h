#include <algorithm>
#include <iostream> 
#include <vector>
#include "AvlTree.h"
using namespace std;

// PQ class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

//TEXTBOOK
template <typename Comparable>
class BinaryHeap
{
    public:
    explicit BinaryHeap( int capacity = 100 );
    explicit BinaryHeap( const vector<Comparable> & items );
    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void insert( Comparable && x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );
    private:
    int currentSize; // Number of elements in heap
    vector<Comparable> array; // The heap array
    void buildHeap( );
    void percolateDown( int hole );
};

template <typename Comparable>
class PQ // heap tree implemented in an array. each array index contains a heapnode struct that points 
{
   // public:
    
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void insert( Comparable && x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );
    //private:
    int currentSize; // Number of elements in heap
    vector<Comparable> Heap; // The heap array
    void buildHeap( );
    void percolateDown( int hole );
  public:
    PQ(int capacity = 100 ) : root{ nullptr }
      { 
        Heap.reserve(capacity);
        
      }
    
    PQ( const vector<Comparable> & items) //: root{ nullptr }
    {
        Heap.reserve(items.size());
        for (int i = 1;i<=items.size(); i++)
        {
            Heap.push_back(items[i]);
        }
       // root = clone( rhs.root );
    }
    
    
    
    PQ( PQ && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~PQ( )
    {
        makeEmpty( );
    }

    /**
     * Deep copy.
     */
    PQ & operator=( const PQ & rhs )
    {
        PQ copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    PQ & operator=( PQ && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }
    //TEXTBOOK: ----------------------------------
    /**
     * Insert item x, allowing duplicates.
    */
    void insert( const Comparable & x )
    {
    if( currentSize == array.size( )-1)
    array.resize( array.size( ) * 2 );

    // Percolate up
    int hole = ++currentSize;
    Comparable copy = x;

    array[ 0 ] = std::move( copy );
    for( ; x < array[ hole / 2 ]; hole /= 2 )
    array[ hole ] = std::move( array[ hole / 2 ] );
    array[ hole ] = std::move( array[ 0 ] );
    }
    //-----------------------------------------------

    void insert( Object x, int y ) // object is our ID, y is our priority, 
    {
        // we want to insert a node into our AVL tree and our array. 
        PQNode
        Insert object x with priority y.
    } 
    
    //TEXTBOOK: ----------------------------------
    /**
     * Remove the minimum item.
    * Throws UnderflowException if empty.
    */
    void deleteMin( )
    {
    if( isEmpty( ) )
    throw UnderflowException{ };

     array[ 1 ] = std::move( array[ currentSize-- ] );
    percolateDown( 1 );
    }
    /**
     * Remove the minimum item and place it in minItem.
    * Throws UnderflowException if empty.
    */
    void deleteMin( Comparable & minItem )
    {
    if( isEmpty( ) )
    throw UnderflowException{ };

    minItem = std::move( array[ 1 ] );
    array[ 1 ] = std::move( array[ currentSize-- ] );
    percolateDown( 1 );
    }

    /**
    * Internal method to percolate down in the heap.
    * hole is the index at which the percolate begins.
    */
    void percolateDown( int hole )
    {
    int child;
    Comparable tmp = std::move( array[ hole ] );

    for( ; hole * 2 <= currentSize; hole = child )
    {
     child = hole * 2;
    if( child != currentSize && array[ child +1]< array[ child ] )
    ++child;
    if( array[ child ] < tmp )
    array[ hole ] = std::move( array[ child ] );
    else
    break;
    }
    array[ hole ] = std::move( tmp );
    }
    //-----------------------------------------------
    
    Object deleteMin()  
    {
        Remove and return the object with smallest priority.
        
    }

    Object & findMin() Return (a reference to) the object with the smallest priority.
    { 
      return    findMin( root )->element
    }

    void updatePriority( Object x, int y )  
    {
         change the priority for object x to y.
    }

    bool isEmpty( )  // Return true if the PQ is empty, otherwise false.
    { 
        return Heap.size()==0;  //condition ? result_if_true : result_if_false ;
        
    }

    int size()  // Return the number of objects in the PQ.
    {
        return Heap.size();
        
    } 

    void makeEmpty( )   
    { 
        Remove all items from the PQ.
    }
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    int height() 
    { 
        //bool search=true;
         if (((root->left)==nullptr)&&((root->right)==nullptr))
        {
            return 0;
        }
        else if (((root->left)==nullptr)&&((root->right)!=nullptr))
        {
            return 1+height(root->right, true);
        }
        else if(((root->right)==nullptr)&&((root->left)!=nullptr))
        {
             return 1+height(root->left, true);
        }
        else
        {
            return max(height(root->left, true), height(root->right, true)) + 1;
        }
    }

    

    int depth( const Comparable & x ) const
    {
        depth( x, root );
    }

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
    void makeEmpty( )
    {
        Heap.clear();
        makeEmpty( root );

    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
     
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

  private:
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
    vector<Comparable> Heap;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, PQNode * & t )
    {
        if( t == nullptr )
            t = new PQNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        
        balance( t );
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, PQNode * & t )
    {
        if( t == nullptr )
            t = new PQNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        
        balance( t );
    }
     
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, PQNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            PQNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
        
        balance( t );
    }
    
    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( PQNode * & t )
    {
        if( t == nullptr )
            return;
        
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
                
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    
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

    PQNode * findMin( PQNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    PQNode * findMax( PQNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const Comparable & x, PQNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, PQNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( PQNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( PQNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    PQNode * clone( PQNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new PQNode{ t->element, clone( t->left ), clone( t->right ), t->height };
    }
        // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height( PQNode *t ) const 
    {
       return t == nullptr ? -1 : t->height;
    }

    int height(PQNode *t, bool find) const
    {
        if (((t->left)==nullptr)&&((t->right)==nullptr))
        {
            return 0;
        }
        else if (((t->left)==nullptr)&&((t->right)!=nullptr))
        {
            return 1+height(t->right, true);
        }
        else if(((t->right)==nullptr)&&((t->left)!=nullptr))
        {
             return 1+height(t->left, true);
        }
        else
        {
            return max(height(t->left, true), height(t->right, true)) + 1;
        }
    }

    int depth( const Comparable & x, PQNode *t ) const
    {
        if( t == nullptr )
        {   
            return -1;
        }
        else if( x < t->element )
        {
            
            return depth( x, t->left )+1;
        }
        else if( t->element < x )
        {
            return depth( x, t->right )+1;
        }
        else // basically: (t->element == x)
        {
            return 0;    // Match
        }
    }
    
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

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( PQNode * & k2 )
    {
        PQNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( PQNode * & k1 )
    {
        PQNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild( PQNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild( PQNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};

#endif
