#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include <iostream> 
using namespace std;

// AvlTree class
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

template <typename Comparable>
class AvlTree
{
  public:
    AvlTree( ) : root{ nullptr }
      { }
    
    AvlTree( const AvlTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }

    /**
     * Deep copy.
     */
    AvlTree & operator=( const AvlTree & rhs )
    {
        AvlTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    AvlTree & operator=( AvlTree && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->TaskID;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->TaskID;
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
        return depth( x, root );
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
        makeEmpty( root );
    }

    /**
     * Insert task id and array index into the tree; duplicates are ignored.
     */
    // void insert( const Comparable & taskid, Comparable & arrayindex )
    // {
    //     insert( taskid, arrayindex, root );
    // }
   
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
    // void deletemin( AvlNode * & t  ) //  deletemin( x, root );
    // {
    //     if( t->left != nullptr && t->right != nullptr ) // Two children
    //     {
    //         t->TaskID = findMin( t->right )->TaskID;
    //         remove( t->TaskID, t->right );
    //     }
    //     else
    //     {
    //         AvlNode *oldNode = t;
    //         t = ( t->left != nullptr ) ? t->left : t->right;
    //         delete oldNode;
    //     }
    //     balance( t );
    // }

    

    // Update the priority of ID x to p
    //    Inserts x with p if s not already in the queue
 
  

  //private:
    struct AvlNode
    {
        Comparable TaskID; //key
        int heapindex;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & TID, int hindex, AvlNode *lt, AvlNode *rt , int h = 0 )
          : TaskID{ TID }, heapindex{ hindex },  left{ lt }, right{ rt }, height{ h }  { }
        
        AvlNode( Comparable && TID, int hindex, AvlNode *lt, AvlNode *rt, int h = 0)
          : TaskID{ std::move( TID ) },heapindex{ hindex } ,  left{ lt }, right{ rt }, height{ h } { }
    };

    AvlNode *root;
    void updatePriority( AvlNode * & t, int taskid, int Arrayindex ) 
    {
         if( t == nullptr )
        {
            cout<<"node not found!"<<endl;
        }
        // else if( taskid < t->TaskID )
        // {
        //     return updatePriority( t->left, taskid, Arrayindex);
        // }
        // else if( t->TaskID < taskid )
        // {
        //     return updatePriority( t->right, taskid, Arrayindex);
        // }
        else // do i only need this?
        { 
            t->heapindex = Arrayindex;// Match
        }
       
    }

    int find( const int &Taskid)
    {
         return find( Taskid, root );
    }

    int find( const int &x, AvlNode *t)
    {
        if( t == nullptr )
        {
            cout<<"node not found!"<<endl;
        }
        else if( x < t->TaskID )
        {
            return find( x, t->left );
        }
        else if( t->TaskID < x )
        {
            return find( x, t->right );
        }
        else
        {
            return t->heapindex;    // Match
        }
    }
    
    
    AvlNode * findPointer( const Comparable & Taskid)
    {
         return findPointer( Taskid, root );
    }

    AvlNode * findPointer( const Comparable & x, AvlNode * t)
    {
        if( t == nullptr )
        {
            cout<<"node not found!"<<endl;
        }
        else if( x < t->TaskID )
        {
            return findPointer( x, t->left );
        }
        else if( t->TaskID < x )
        {
            return findPointer( x, t->right );
        }
        else
        {
            return t;    // Match
        }
    }

    int deleteMin( AvlNode * &t  ) //  deletemin( x, root );
    {

        
         if (((t->left)==nullptr)&&((t->right)==nullptr)) //no children
        {
            int ID=t->TaskID;
            delete t;
            cout<<t->TaskID<<endl;
            cout<<"min deleted in avl"<<endl;
            t = nullptr;
            //cout<<t->TaskID<<endl;
            return ID;
        }
        else if (((t->left)==nullptr)&&((t->right)!=nullptr)) // right child exists
        {
            int ID=t->TaskID;
            AvlNode *oldNode = t;
            t = t->right;
            delete oldNode;
            return ID;
        }
        else if(((t->right)==nullptr)&&((t->left)!=nullptr)) // left child exists
        {
            int ID=t->TaskID;
            AvlNode *oldNode = t;
            t = t->left;
            delete oldNode;
            return ID;
        }
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            int ID=t->TaskID;
            t->TaskID = findMin( t->right )->TaskID; // find successor and replace
            remove( t->TaskID, t->right );// delete sucessor
            return ID;
        }
        balance( t );
    }

     AvlNode* insert( const Comparable & taskid, int & arrayindex )
    {
        //cout<<"if 4"<<endl;
        insert( taskid, arrayindex, root );
        //balance(root);
        return findPointer(taskid);
    }


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    
    // void insert( const Comparable & x,Comparable & y, AvlNode * & t ) //insert( taskid, arrayindex, root );
    // { 
    //     if( t == nullptr )
    //         t = new AvlNode{ x, y, nullptr, nullptr };
    //     else if( x < t->TaskID )
    //         insert( x, y, t->left );
    //     else if( t->TaskID < x )
    //         insert( x, y, t->right );
        
    //     balance( t );
    // }

    //AvlNode* insert( const Comparable & x,Comparable & y, AvlNode * & t ) //insert( taskid, arrayindex, root );
    void insert( const Comparable & x,Comparable & y, AvlNode * & t ) //insert( taskid, arrayindex, root );
    { 
        
        if( t == nullptr )
        {
            t = new AvlNode{ x, y, nullptr, nullptr };
            //cout<<"if 1"<<endl;
            //AvlNode* temp= t;
        }
        else if( x < t->TaskID )
        {
           // cout<<t->TaskID<<endl;
            insert( x, y, t->left );
            //cout<<"If 2"<<endl;
        }
        else if( t->TaskID < x )
        {
           // cout<<t->TaskID<<endl;
            insert( x, y, t->right );
            //cout<<"if 3"<<endl;
        }
        
        // cout<<"Before Balance: "<<t->TaskID<<endl;
        // cout<<"Address: "<<t<<endl;
         balance( t );
        // cout<<"After Balance: "<<t->TaskID<<endl;
        // cout<<"Address: "<<t<<endl;
        //return temp;
        //return t; // CAN I do this? --------------------------------------------------------?
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    // void insert( Comparable && x, AvlNode * & t )
    // {
    //     if( t == nullptr )
    //         t = new AvlNode{ std::move( x ), nullptr, nullptr };
    //     else if( x < t->TaskID )
    //         insert( std::move( x ), t->left );
    //     else if( t->TaskID < x )
    //         insert( std::move( x ), t->right );
        
    //     balance( t );
    // }
     
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        
        if( x < t->TaskID )
            remove( x, t->left );
        else if( t->TaskID < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->TaskID = findMin( t->right )->TaskID;
            remove( t->TaskID, t->right );
        }
        else
        {
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
        
        balance( t );
    }

    // void deletemin( const Comparable & x )
    // {
    //     deletemin( x, root );
    // }
    
    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( AvlNode * & t )
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
    AvlNode * findMin( AvlNode *t ) const
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
    AvlNode * findMax( AvlNode *t ) const
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
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->TaskID )
            return contains( x, t->left );
        else if( t->TaskID < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, AvlNode *t ) const
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
    void makeEmpty( AvlNode * & t )
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
    void printTree( AvlNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            cout << t->TaskID << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode{ t->TaskID, clone( t->left ), clone( t->right ), t->height };
    }
        // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height( AvlNode *t ) const 
    {
       return t == nullptr ? -1 : t->height;
    }

    int height(AvlNode *t, bool find) const
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

    int depth( const Comparable & x, AvlNode *t ) const
    {
        if( t == nullptr )
        {   
            return -1;
        }
        else if( x < t->TaskID )
        {
            
            return depth( x, t->left )+1;
        }
        else if( t->TaskID < x )
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
    void displayLinks( AvlNode *t, int depth, ostream & out ) const
    {
        
        const int SHIFT = 4 ;
        if( t != nullptr )
        {
            for( int i = 0 ; i < SHIFT*depth ; i++ )
            { 
                out << " " ; 
            }
            
            out << t->TaskID << ") @:" << t << "   " << "L:" << t->left << "   " << "R:" << t->right << endl;
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
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
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
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
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
    void doubleWithLeftChild( AvlNode * & k3 )
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
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};

#endif
