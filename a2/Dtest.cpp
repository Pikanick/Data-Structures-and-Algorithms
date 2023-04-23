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
    cout << "Start of depth(x) implementation test" << endl;

     for( int k = 0 ; k < NUMS ; k++ )// construct array with membership test time for T1. 
    {    
        BST1.insert( randArray[k] );
    }

    cout<<endl;

    for( int k = 0 ; k < NUMS ; k++ ) // construct array with membership test time for T1. 
    { 
        BST2.insert( randArray2[k] );
    }

    
        cout<<"BST1: "<< endl;
        cout<<"Height of Tree: "<< BST1.height()<< endl; // ------------------- PUT THIS BACK IN 
        cout <<"Tree & Links: "<< endl ;
        BST1.displayLinks(); 
        cout<<endl;

        cout<<"BST2: "<< endl;
        cout<<"Height of Tree: "<< BST2.height()<< endl; // ------------------- PUT THIS BACK IN 
        cout << "Tree & Links: " << endl ;
        BST2.displayLinks(); 
    
    cout<<endl;
    float D1[NUMS],D2[NUMS]; //array with depth of searches for each index in array of values for tree 1 and tree 2 respectively


    for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T1. 
    { 
        D1[p]=BST1.depth(randArray[p]);
        
    }
    cout<<"BST1: "<< endl;

    for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
        cout <<"Depth of node "<<randArray[i]<<" is: "<<D1[i]<< endl;//", ";
    }
    cout<<endl;

     for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T2. 
    { 
        D2[p]=BST2.depth(randArray2[p]);
       
    }

    cout<<"BST2: "<< endl;
    for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
        cout <<"Depth of node "<<randArray2[i]<<" is: "<<D2[i]<< endl;//", ";
    }

    cout<<endl;
    cout << "End of Dtest" << endl;
    return 0;
}
