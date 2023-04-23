#include <iostream>
#include "LinkedList.h"
#include "UnrolledList.h"
#include <time.h>
using namespace std;

// double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   
//     return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
// } 
// Driver Code
// int main()
// {
	

// 	// Inserting nodes
	
// 	list.insertNode(2);
// 	list.insertNode(3);
// 	list.insertNode(4);

// 	cout << "Elements of the list are: ";

// 	// Print the list
// 	list.printList();
// 	cout << endl;

// 	// Delete node at position 2.
// 	list.deleteNode(2);

// 	cout << "Elements of the list are: ";
// 	list.printList();
// 	cout << endl;
// 	return 0;
// }

//unrolled_list
//Main function to demonstrate the above functions
// int main()
// {
//     unrolled_list uls;
//     int ch,flag=1;
//     while(flag)
//     {   //system("cls"); Clears output screen
//         cout<<"Enter the choice:\n";
//         cout<<"1.Insert Node\n2.Display List\n3.Exit\n";
//         cin>>ch;
//         switch(ch)
//         {
//             case 1: uls.add_node();
//                     break;
//             case 2: uls.display_list();
//                     break;
//             case 3: flag=0;
//         }
//     }
//     return 0;
// }

int main()
{
    Linkedlist list;
    unrolled_list uls;
    int ch,flag=1;
    clock_t start, finish ;// used for getting the time. 
    double time_taken =0;
    int size=100000;
    int *A= new int[size];
    //int steps=100000;
    int *B= new int[size];
    //cout<<"Hi "<<endl;
    double time1[size], time2[size];
    
    double total1=0.0, total2=0.0, ave1=0.0, ave2=0.0;

    int y=0;
    for(int i=0; i<size; i++)
    {
        A[i]=i;
        B[i]=i;
    }

    int j=0;
    start = clock(); 
    for(int i=0; i<size; i++)
    {
        
        B[i]*=3;
           
    }
    finish = clock(); 
    time_taken = elapsed_time(start,finish); 
    // time2[j]=time_taken;
    // total2+=time2[j];
    // j++; 
    // ave2=total2*64/size;
    cout<<"time taken to traverse Array: "<<time_taken<<endl;
    cout<<"Please enter an integer to continue: "<<endl;
    cin>>y;
    j=0;
    for(int i=0; i<10; i++)// for 20,000 nodes
    {
        // for( j=0; j<5; j++)//5 elements per node
        // {
            uls.add_node(B,10000);
           
        // }
    }
    
    for(int i=0; i<100000; i++)// for 20,000 nodes
    {
        // for( j=0; j<5; j++)//5 elements per node
        // {
            list.insertNode(B[i]);
           
        // }
    }
    // int i=1;
    // if(uls.first==nullptr)   //To check if the list is empty
    // {
    //     cout<<"Empty List!";
    //     //getch();
    //     return;
    // }

    // int j=0;
    // start = clock(); 
    // while(nod!=nullptr)
    // {
    //     cout<<"Node "<<i<<":"<<endl;
    //     for(int j=0;j<nod->length;j++)
    //         cout<<nod->arr[j]<<" ";
    //     cout<<endl<<endl;
    //     i++;
    //     nod=nod->next;
    // }
    // finish = clock(); 
    // time_taken = elapsed_time(start,finish); 
    // // time1[j]=time_taken;
    // // total1+=time1[j];
    // // j++;    
    // // ave1=total1/size;
    // cout<<"Traversal time for Unrolled Linked List: "<<ave1<<endl;
    //getch();

    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    // uls.add_node(B,10000);// 10 elements per node
    int x;
    uls.display_list();
    cout<<"Please enter an integer to continue: "<<endl;
    cin>>x;
    

	// Print the list
	// list.printList();
	// cout << endl;

    Node* temp = list.head;
    
	// Check for empty list.
	if (list.head == NULL) {
		cout << "List empty" << endl;
		return 0;
	}
	cout << "Elements of the list are: ";
	// Traverse the list.
	start = clock(); 
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	finish = clock(); 
	time_taken = elapsed_time(start,finish);
    cout<<endl<<endl;
	cout<<"Traversal time for Singly Linked List: "<<time_taken<<" ms"<<endl;
 
   

   // cout<<"hello"<<endl;
    // while(flag)
    // {   //system("cls"); Clears output screen
    //     cout<<"Enter the choice:\n";
    //     cout<<"1.Insert Node\n2.Display List\n3.Exit\n";
    //     //cin>>ch;

    //     switch(ch)
    //     {
    //         case 1: uls.add_node();
    //                 break;
    //         case 2: uls.display_list();
    //                 break;
    //         case 3: flag=0;
    //     }
    // }
    return 0;
}