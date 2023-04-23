#include<iostream>
#include<cstdlib>
#include <time.h>
//#include<conio.h>
using namespace std;
#define maxlength 100000
//Node contents


clock_t start, finish ;// used for getting the time. 
double time_taken =0;
const int size=100000;
double time1[size], time2[size];
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
    node* nod=first;
    int j=0;
    start = clock(); 
    while(nod!=nullptr)
    {
        cout<<"Node "<<i<<":"<<endl;
        for(int j=0;j<nod->length;j++)
            cout<<nod->arr[j]<<" ";
        cout<<endl<<endl;
        i++;
        nod=nod->next;
    }
    finish = clock(); 
    time_taken = elapsed_time(start,finish); 
    // time1[j]=time_taken;
    // total1+=time1[j];
    // j++;    
    // ave1=total1/size;
    cout<<"Traversal time for Unrolled Linked List: "<<time_taken<<" ms"<<endl;
    //getch();
}

