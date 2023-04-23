#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> BST1;
    BinarySearchTree<int> BST2;
    const int NUMS = 40; // number of nodes
     srand(time(NULL));
    cout << "Start of displayLinks() Implementation Test" << endl;
    
  
    int randArray [NUMS];
    for(int i=0;i<NUMS;i++)
    {
      randArray[i]=rand()%100;  //Generate number between 0 to 99
    }
    
    int randArray2 [NUMS];
    for(int i=0;i<NUMS;i++)
    {
      randArray2[i]=2*(rand()%100);  //Generate number between 0 to 99
    }

    for( int k = 0 ; k < NUMS ; k++ )// construct T1. 
    { 
        BST1.insert( randArray[k] );
    }


    for( int k = 0 ; k < NUMS ; k++ ) // construct T1. 
    { 
        BST2.insert( randArray2[k] );
    }
  
    cout<<"BST2: "<< endl;
    cout <<"Tree & Links: "<< endl ;
    BST1.displayLinks(); 
    cout<<endl;
    cout<<"BST2: "<< endl;
    cout << "Tree & Links: " << endl ;
    BST2.displayLinks(); 

    cout<<endl;
    cout << "End of DLtest" << endl;
    return 0;
}
