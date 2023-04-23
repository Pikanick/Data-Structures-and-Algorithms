#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> T1;
    BinarySearchTree<int> T2;
    int NUMS = 40; // number of nodes
     srand(time(NULL));
    int randArray [40];
    for(int i=0;i<NUMS;i++)
    {
      randArray[i]=rand()%100;  //Generate number between 0 to 99
    }

    cout << "Start of BST Height test" << endl;
    int TA1[8]={25, 30, 15, 17, 12, 14, 9, 10};
   
    for( int k = 0 ; k < 8 ; k++ ){ // construct T1. 
 
         T1.insert( TA1[k] );
    }
    
    for( int k = 0 ; k < NUMS ; k++ ){ // construct T2. 
 
        T2.insert( randArray[k] );
    }
        cout<<"BST1: "<< endl;
        cout << "Tree + Links:" << endl ;
        T1.displayLinks(); 
        cout<<"Height of Tree: "<< T1.height()<< endl;
        cout<<"BST2: "<< endl;
        cout << "Tree + Links:" << endl ;
        T2.displayLinks(); 
        cout<<"Height of Tree: "<< T2.height()<< endl;

    cout << "End of BST Height test" << endl;

    return 0;
}
