#include <iostream>
#include "PQ.h"
using namespace std;

int main()
{
    //int x;
    int NUMS=10;
    //cout<<"hello"<<endl;
    PQ<int> PQ1;
    vector<int> Tasks;
    vector<int> priorities;
    cout<<"Task ID's: "<<endl;
    for (int i=0; i<NUMS; i++)
    {
        Tasks.push_back(i);
        cout<< Tasks[i]<<endl;
    }

    int Nums=NUMS;
    cout<<"Task Priorities: "<<endl;
    for (int i=0; i<NUMS; i++)
    {
        priorities.push_back(Nums);
        cout<< priorities[i]<<endl;
        Nums++;
    }
 
    PQ<int> PQ2(Tasks, priorities);
    PQ2.DisplayPQ();
    cout<<endl;
    const AvlTree<int>::AvlNode & y=PQ2.findMin();
    cout<<"Task ID of Minimum Priority in PQ: "<<y.TaskID<<endl;
    //PQ2.AVLTHeap.displayLinks();
    cout<<PQ2.isEmpty()<<endl;
    cout<<PQ1.isEmpty()<<endl;
    cout<<"Size of non empty PQ: "<<PQ2.size()<<endl;
    cout<<"Size of empty PQ: "<<PQ1.size()<<endl;
    // int z= 0;//9; // Task id
    // int a= 15;//5;// priority
    // PQ2.updatePriority(z,a);
    
    // int z= 8; // Task id
    // int a= 12;// priority
    // PQ2.updatePriority(z,a);

    // int z= 0; // Task id
    // int a= 15;// priority
    // PQ2.updatePriority(z,a);
    // const int & TskID= PQ2.deleteMin();
    // cout<<"Deleted node Task ID: "<<endl;
    // cout<<"PQ after deleteMin(): "<<endl;
    // PQ2.DisplayPQ();

    int z= 9; // Task id
    int a= 13;// priority
    PQ2.updatePriority(z,a);

    cout<<"PQ After calling updatePriority(9,13): "<<endl;
    PQ2.DisplayPQ();
    cout<<"Index in heap of node with Task ID: 9 and updated Priority: 13 is: "<<PQ2.AVLTHeap.find(z)<<endl;

    PQ2.makeEmpty();
    PQ1.makeEmpty();
    
    cout<<PQ2.isEmpty()<<endl;
    cout<<PQ1.isEmpty()<<endl;

    
    //cin>>x;
    return 0;
    
}