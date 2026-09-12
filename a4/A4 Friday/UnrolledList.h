#include<iostream>
#include<cstdlib>
#include <time.h>
//#include<conio.h>
using namespace std;
#define maxlength 100000
//Node contents


clock_t start, finish ;// used for getting the time. 
double time_taken =0;
// Renamed from "size": at global scope, alongside "using namespace std;"
// (here and in exp3.cpp, which includes this header), that name collided
// with the std::size() function template and made every use of it a hard
// compile error ("reference to 'size' is ambiguous") on any compiler new
// enough to have std::size (introduced in C++17) -- this header hasn't
// compiled at all under a reasonably current compiler.
const int UNROLLED_LIST_TIMING_SIZE=100000;
double time1[UNROLLED_LIST_TIMING_SIZE], time2[UNROLLED_LIST_TIMING_SIZE];
double total1=0.0, total2=0.0, ave1=0.0, ave2=0.0;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

struct node
{
 int length;
 int arr[maxlength];
 node* next;
};
//Class to demonstrate the linked list
class unrolled_list
{  public: 
    node* first;
    node* last;

    unrolled_list();
    // void add_node(int (&x)[maxlength], int arraylength);
    void add_node(int x[], int arraylength);
    void display_list();
};
//Constructor which initiates the head and tail of the linked list as null 
unrolled_list::unrolled_list()
{
    first=nullptr;
    last=nullptr;
}
//Function to add a node to the linked list
// void unrolled_list::add_node(int (&x)[maxlength], int arraylength)
void unrolled_list::add_node(int x[], int arraylength)
{   //system("cls");
    int num;
    node* nod= new node;
    //If the pointer nod isn't created then it means that the machine has insufficient memory
    if(nod==nullptr)
    {
        cout<<"Memory Insufficient!";
        return;
    }
    // cout<<"Enter the number of elements to be added to the node:";
    // cout<<"( The number must be less than "<<maxlength<<" ) \n";
    //cin>>nod->length;
    nod->length=arraylength;
    // cout<<"Enter the elements:\n";
    for(int i=0;i<nod->length;i++)
        // cin>>nod->arr[i];
        nod->arr[i]=x[i];
    if(first==nullptr) //Case for the first node adition
    {
        first=nod;
        last=first;
        last->next=nullptr;
    }
    else              // Case for adding other nodes
    {
        last->next=nod;
        nod->next=nullptr;
        last=nod;
    }
}
//Function to dispaly the linked list items
void unrolled_list::display_list()
{   //system("cls");
    int i=1;
    if(first==nullptr)   //To check if the list is empty
    {
        cout<<"Empty List!";
        //getch();
        return;
    }
    // Just displays the list contents -- no timing here. The actual
    // traversal-time comparison against the singly linked list lives in
    // exp3.cpp, measured without any cout in the timed loop (printing
    // ~100,000 lines while the clock is running would make I/O cost
    // dominate the measurement, defeating the point of the experiment).
    // This function used to *also* time itself this way and print
    // "Traversal time for Unrolled Linked List", which both duplicated
    // and contaminated the real measurement in exp3.cpp.
    node* nod=first;
    while(nod!=nullptr)
    {
        cout<<"Node "<<i<<":"<<endl;
        for(int j=0;j<nod->length;j++)
            cout<<nod->arr[j]<<" ";
        cout<<endl<<endl;
        i++;
        nod=nod->next;
    }
    //getch();
}

