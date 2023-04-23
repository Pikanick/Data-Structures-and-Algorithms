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
        if((pointers.size()<pointers.capacity())&&(priorities.size()<priorities.capacity()))
        {
            pointers.push_back(t);
            priorities.push_back(p);
        }

        else
        {
            pointers.reserve(2*pointers.capacity());
            priorities.reserve(2*priorities.capacity());
            pointers.push_back(t);
            priorities.push_back(p);
        }

        percolateUp();

    }

    void percolateUp()
    {
        int v,p;
        v=priorities.size();//child
        p=floor((v-1)/2);//parent

        while(v>0 && priorities.at(v)<priorities.at(p) )
        {
            swap(priorities.at(v),priorities.at(p));
            swap(pointers.at(v),pointers.at(p));
            v=p;
            p=floor((v-2)/2);
        }
        //return v;

        // int v,p;
        // v=pointers.size();//child
        // p=pointers.at((v-1)/2);//parent

        // while(v>0 && pointers.at(v)<pointers.at(p) )
        // {
        //     swap(pointers.at(v),pointers.at(p));
        //     v=p;
        //     p=(v-2)/2;
        // }

        // int v2,p2;
        // v2=priorities.size();//child
        // p2=priorities.at((v-1)/2);//parent

        // while(v2>0 && priorities.at(v2)<priorities.at(p2) )
        // {
        //     swap(priorities.at(v2),priorities.at(p2));
        //     v2=p2;
        //     p2=(v2-2)/2;
        // }

    }

    int percolateUp(int hepindex)
    {
        int v2,p2;
        v2=hepindex;//child
        p2=floor((v2-1)/2);//parent

        while(v2>0 && priorities.at(v2)<priorities.at(p2) )
        {
            swap(priorities.at(v2),priorities.at(p2));
            swap(pointers.at(v2),pointers.at(p2));
            v2=p2;
            p2=floor((v2-2)/2);
        }
        return v2;

    }

    void percolateDown()
    {
        int v=0;//parent

        while((2*v+1)<priorities.size())// while v2 not a leaf
        {
            int child= 2*v+1; // left child
            if(((2*v+1)<priorities.size())&& (priorities.at(2*v+2)<priorities.at(2*v+1)))
            {
                child= 2*v+2; // right child if exists and has smaller key
            }

            if(priorities.at(child)<priorities.at(v))
            {
                swap(priorities.at(child),priorities.at(v));
                swap(pointers.at(child),pointers.at(v));
                v=child;
            }
            if((priorities.at(2*v+1)>priorities.at(v))&&(priorities.at(2*v+2)>priorities.at(v)))
            {    
                cout<<"Percolate Down Done!"<<endl;
                break;
            }
        }

        // int v,p;
        // v=pointers.size();//child
        // p=pointers.at((v-1)/2);//parent

        // while(v>0 && pointers.at(v)<pointers.at(p) )
        // {
        //     swap(pointers.at(v),pointers.at(p));
        //     v=p;
        //     p=(v-2)/2;
        // }

        // int v2,p2;
        // v2=priorities.size();//child
        // p2=priorities.at((v-1)/2);//parent

        // while(v2>0 && priorities.at(v2)<priorities.at(p2) )
        // {
        //     swap(priorities.at(v2),priorities.at(p2));
        //     v2=p2;
        //     p2=(v2-2)/2;
        // }

    }

    int percolateDown(int hapindex)
    {
        int v=hapindex;//parent
        int k;
        cout<<"Child Priority: "<<priorities.at(2*v+1)<<" Parent Priorty: "<<priorities.at(v)<<endl;
       
        while((2*v+1)<priorities.size())// while v2 not a leaf
        {
            cout<<"Helloooo6"<<endl;
            int child= 2*v+1; // left child
            if(((2*v+1)<priorities.size())&& (priorities.at(2*v+2)<priorities.at(2*v+1)))
            {
                cout<<"Helloooo7"<<endl;
                child= 2*v+2; // right child if exists and has smaller key
            }

            if(priorities.at(child)<priorities.at(v))
            {
                
                cout<<"Helloooo8"<<endl;
                swap(priorities.at(child),priorities.at(v));
                swap(pointers.at(child),pointers.at(v));
                v=child;
                cout<<"left Child Priority: "<<priorities.at(2*v+1)<<", Right Child Priority: "<<priorities.at(2*v+2)<<", Parent Priorty: "<<priorities.at(v)<<endl;
                cin>>k;
            }

            if((priorities.at(2*v+1)>priorities.at(v))&&(priorities.at(2*v+2)>priorities.at(v)))
            {    
                cout<<"Helloooo9"<<endl;
                break;
            }
        }
        cout<<"Helloooo9"<<endl;
        return v;
    }

    //AvlTree<int>::AvlNode *  deleteMin()// delete minimum from vectors (element at index 0)
    void  deleteMin()// delete minimum from vectors (element at index 0), Returns Task ID of deleted element
    {
        // AvlTree<int>::AvlNode* temp= pointers.at(0);
        //Comparable temp= pointers.at(0)->TaskID;
       // cout<<"during Heap Task ID: "<<temp<<endl;
        if((pointers.size()>0)&&(priorities.size()>0))
        {
            pointers.erase(pointers.begin());
            priorities.erase(priorities.begin());
        }

        else
        {
            //cout<<"Test 1"<<endl;
            cout<<"Heap is empty!"<<endl;
        }
        percolateDown();
        //cout<<"just after Heap Task ID: "<<temp<<endl;
        //return temp;
    }

     AvlTree<int>::AvlNode & findMin() const// return highest (smallest) priority reference to object
    {
        if((pointers.size()>0)&&(priorities.size()>0))
        {
            AvlTree<int>::AvlNode & x=*(pointers.at(0));
            //AvlTree<int>::AvlNode * &y=x;
            return x;
        }

        else
        {
            //cout<<"Test 2"<<endl;
            cout<<"Heap is empty!"<<endl;
        }

    }
    
    bool isEmpty() const // check if heap vector sizes= 0
    {
        if((pointers.size()==0)&&(priorities.size()==0))
        {
            cout<<"Heap is empty!"<<endl;
            return true;

        }

        else
        {
            //cout<<"Test 3"<<endl;
            cout<<"Heap has items inside!"<<endl;
            return false;
        }

    }
    
    int size() const// return size of heap vectors
    {
        if(pointers.size()==priorities.size())
        {
            return pointers.size();

        }
        else
        {
            cout<<"Arrays have different size!"<<endl;
        }
    }

    void makeEmpty()// clear vectors
    {
        if((pointers.size()>0)&&(priorities.size()>0))
        {
            //cout<<"Test 5"<<endl;
            pointers.clear();
            priorities.clear();
        }

        else
        {
            //cout<<"Test 4"<<endl;
            cout<<"Heap is empty!"<<endl;
        }
    }
    
    // Update the priority of ID x to p
    //    Inserts x with p if s not already in the queue
   // void updatePriority( const ID & x, int p ) 

    int updatePriority(int heapindex, int p)// change priority member, reorganize heap return new index
    {
        
        int newindex;
        AvlTree<int>::AvlNode * temp=  pointers.at(heapindex);
        int temp2=  priorities.at(heapindex); //temp2=k, p=j
        priorities[heapindex] = p;
        //cout<<"Helloooo5"<<endl;
        
        if(temp2>p) 
        {
            //cout<<"Helloooo3"<<endl;
            newindex= percolateUp(heapindex);
           // cout<<"PercolateUp was called"<<endl;
        }
        else if(temp2<p)
        {
           //  cout<<"Helloooo4"<<endl;
            newindex = percolateDown(heapindex);
           // cout<<"PercolateDown was called"<<endl;
        }
        //cout<<"Nothing happened"<<endl;
        return newindex;
    }
};
