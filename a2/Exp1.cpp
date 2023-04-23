#include <iostream>
#include "BinarySearchTree.h"
#include <time.h>

double elapsed_time( clock_t start, clock_t finish)// returns elapsed time in milliseconds
{  
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000.0); 
} 
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> T1;
    BinarySearchTree<int> T2;
    const int NUMS = 50000; // number of nodes
    clock_t start, finish ;// used for getting the time. 
    srand(time(NULL));

    cout << "Start of Experiment 1" << endl;
   // int TA1[8]={25, 30, 15, 17, 12, 14, 9, 10};
    //int TA2[8]={15, 17, 12, 25, 14, 9, 30, 10};
    //int TA3[8]={14, 9, 25, 15, 17, 12, 30, 10};

    // int randArray [NUMS];
    // for(int i=0;i<NUMS;i++)
    // {
    //   randArray[i]=rand()%NUMS;  //Generate number between 0 to 9999
    // }

    int randArray2 [NUMS];
    for(int i=0;i<NUMS;i++) // Tall and skinny BST
    {
      randArray2[i]= i+1;  //Generate number between 0 to 99
    }

    int randArray3 [NUMS];
    int j=0;
    for(int i=NUMS;i>0;i--) // Short and Bushy BST
    {
        j=rand()%i;
        //swap(randArray2(i), randArray2(j));
      randArray3[i]=randArray2[j];  //Generate number between 0 to 9999
    }



    for( int k = 0 ; k < NUMS ; k++ ){ // construct array with membership test time for T1. 
        
        T1.insert( randArray2[k] );
        T2.insert( randArray3[k] );
    }
    
        // cout<<"T1: "<< endl;
        // cout << "Tree + Links:" << endl ;
        // T1.displayLinks(); 
        
        // cout<<"T2: "<< endl;
        // cout << "Tree + Links:" << endl ;
        // T2.displayLinks(); 

    double Time1[NUMS],Time2[NUMS], sum1=0.0, sum2=0.0, average1=0.0, average2=0.0;
    double D1[NUMS],D2[NUMS]; //array with depth of searches for each index in array of values for tree 1 and tree 2 respectively
    double ADS1=0.0, ADS2=0.0;// average depth of search for tree 1 and tree 2 respectively
    double dsum1=0.0, dsum2=0.0; //sum of depth of searches for each tree.

    cout<<"Tall and Skinny Tree: "<< endl;
    cout<<"Height of Tree: "<< T1.height()<< endl;
    cout<<"Natural and Realistic Tree: "<< endl;
    cout<<"Height of Tree: "<< T2.height()<< endl;
        
    for(int i = 0 ; i < NUMS ; i++ ){ // construct array with membership test time for T1. 
        start = clock(); 
        //cout<<start<<endl;
        T1.contains( randArray2[i] );
        finish = clock();
        //cout<<finish<<endl;
        double time_taken = elapsed_time(start,finish);
        //cout <<time_taken<< ", ";
        Time1[i]= time_taken;
        sum1 += Time1[i];
    }
    cout<<endl;
    average1 = sum1 / NUMS;
    cout << "Average Insertion time for Tall and Skinny Tree = " << average1<<endl;

    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<Time1[i]<< ", ";
    // }
    // cout<<endl;

    for(int j = 0 ; j < NUMS ; j++ ){ // construct array with membership test time for T2. 
        
        start = clock(); 
        //cout<<start<<endl;
        T2.contains( randArray3[j] );
        finish = clock();
        //cout<<finish<<endl;
        double time_taken = elapsed_time(start,finish);
        //cout <<time_taken<< ", ";
        Time2[j]= time_taken;
        sum2 += Time2[j];
    }

    average2 = sum2 / NUMS;
    cout << "Average Insertion time for Natural Tree = " << average2<<endl;

    //  for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<Time2[i]<< ", ";
    // }
    // cout<<endl;

    for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T1. 
    { 
        D1[p]=T1.depth(randArray2[p]);
        dsum1 += D1[p];
    }

    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<D1[i]<< ", ";
    // }
    // cout<<endl;

    ADS1 = dsum1 / NUMS;
    cout << "Average depth of search for Tall and Skinny Tree = " << ADS1 <<endl;

     for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T1. 
    { 
        D2[p]=T2.depth(randArray3[p]);
        dsum2 += D2[p];
    }

    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<D2[i]<< ", ";
    // }
    // cout<<endl;

    ADS2 = dsum2 / NUMS;
    cout << "Average depth of search for Natural Tree = " << ADS2 <<endl;
    cout << "End of Experiment 1" << endl;

    return 0;
}
