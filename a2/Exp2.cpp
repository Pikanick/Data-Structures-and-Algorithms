#include <iostream>
#include "AvlTree.h"
#include "BinarySearchTree.h"
#include <time.h>

double elapsed_time( clock_t start, clock_t finish)// returns elapsed time in milliseconds
{  
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 
using namespace std;

    // Test program
int main( )
{   
    AvlTree<int> AVLT1;
    BinarySearchTree<int> BST1;
    const int NUMS = 10000;// number of nodes
    clock_t start, finish ;// used for getting the time. 
    srand(time(NULL));

    cout << "Start of Experiment 2" << endl;
    //int TA1[8]={25, 30, 15, 17, 12, 14, 9, 10};
    //int TA3[8]={14, 9, 25, 15, 17, 12, 30, 10};
    //int randArray [NUMS];
    
    int randArray2 [NUMS];
    for(int i=0;i<NUMS;i++) // Tall and skinny BST
    {
      randArray2[i]= i+1;  //Generate number between 0 to 99
    }

    // for(int i=0;i<NUMS;i++)
    // {
    //   randArray[i]=rand()%10000;  //Generate number between 0 to 99
    // }

    double  Total1=0.0, Total2=0.0, Ave1=0.0, Ave2=0.0;
    double IT1[NUMS],IT2[NUMS]; //array with depth of searches for each index in array of values for tree 1 and tree 2 respectively

    for( int k = 0 ; k < NUMS ; k++ )// construct array with membership test time for T1. 
    { 
        start = clock(); 
        AVLT1.insert( randArray2[k] );
        finish = clock(); 
        double time_taken = elapsed_time(start,finish); 
        IT1[k]= time_taken;
        Total1 += IT1[k];
    }

    cout<<endl;
    Ave1 = Total1 / NUMS;
    cout << "Average Insetion time for Avl Tree = " << Ave1<<endl;
    cout<<endl;

    for( int k = 0 ; k < NUMS ; k++ ) // construct array with membership test time for T1. 
    { 
        start = clock(); 
        BST1.insert( randArray2[k] );
        finish = clock(); 
        double time_taken = elapsed_time(start,finish); 
        IT2[k]= time_taken;
        Total2 += IT2[k];
    }

    Ave2= Total2 / NUMS;
    cout << "Average Insertion time for BST = " << Ave2<<endl;
    cout<<endl;
    cout<<"AVLT1: "<< endl;
    cout<<"Height of Tree: "<< AVLT1.height()<< endl; 
    // cout <<"Tree & Links: "<< endl ;
    // AVLT1.displayLinks(); 
    
    cout<<endl;

    cout<<"BST1: "<< endl;
    cout<<"Height of Tree: "<< BST1.height()<< endl; 
    // cout << "Tree & Links: " << endl ;
    // BST1.displayLinks(); 
        
    
    cout<<endl;
    float Time1[NUMS],Time2[NUMS], sum1=0.0, sum2=0.0, average1=0.0, average2=0.0;
    float D1[NUMS],D2[NUMS]; //array with depth of searches for each index in array of values for tree 1 and tree 2 respectively
    float ADS1=0.0, ADS2=0.0;// average depth of search for tree 1 and tree 2 respectively
    float dsum1=0.0, dsum2=0.0; //sum of depth of searches for each tree.

    float D5[NUMS],D6[NUMS]; //array with depth of searches for each index in array of values for tree 1 and tree 2 respectively
    float ADS5=0.0, ADS6=0.0;// average depth of search for tree 1 and tree 2 respectively
    float dsum5=0.0, dsum6=0.0; //sum of depth of searches for each tree.

    for(int i = 0 ; i < NUMS ; i++ ){ // construct array with membership test time for T1. 
        start = clock(); 
        //AVLT1.contains( randArray[i] );
        AVLT1.contains( randArray2[i] );
        finish = clock();
        double time_taken = elapsed_time(start,finish);
        //cout <<time_taken<< ", ";
        Time1[i]= time_taken;
        sum1 += Time1[i];
    }
    cout<<endl;
    average1 = sum1 / NUMS;
    cout << "Mean Membership Test Time for AVL Tree = " << average1<<endl;

    cout<<endl;
    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<Time1[i]<< ", ";
    // }
    cout<<endl;

    for(int j = 0 ; j < NUMS ; j++ ){ // construct array with membership test time for T2. 
        
        start = clock(); 
        //BST1.contains( randArray[j] );
        BST1.contains( randArray2[j] );
        finish = clock();
        double time_taken = elapsed_time(start,finish);
        Time2[j]= time_taken;
        sum2 += Time2[j];
    }

    average2 = sum2 / NUMS;
    cout << "Mean Membership Test Time for BST = " << average2<<endl;
    double min1=10000;

    for(int i = 0; i < NUMS; i++){
        if(Time1[i] < min1){
            min1 = Time1[i];
        }
    }
 
    cout << "Minimum Membership Test Time for AVL Tree = " << min1<<endl;
    double min2=10000;

    for(int i = 0; i < NUMS; i++){
        if(Time2[i] < min2){
            min2 = Time2[i];
        }
    }
 
    cout << "Minimum Membership Test Time for BST = " << min2<<endl;
    double max1=0;

    for(int i = 0; i < NUMS; i++){
        if(Time1[i] > max1){
            max1 = Time1[i];
        }
    }
 
    cout << "Maximum Membership Test Time for AVL Tree = " << max1<<endl;
    double max2=0;

    for(int i = 0; i < NUMS; i++){
        if(Time2[i] > max2){
            max2 = Time2[i];
        }
    }
 
    cout << "Maximum Membership Test Time for BST = " << max2<<endl;
    cout<<endl;
   
    for( int p = 0 ; p < NUMS ; p++ ) // construct array with key depths for T1. 
    { 
        D5[p]=AVLT1.depth(randArray2[p]);
        dsum5 += D5[p];
    }
    for( int p = 0 ; p < NUMS ; p++ ) // construct array with key depths for T2. 
    { 
        D6[p]=BST1.depth(randArray2[p]);
        dsum6 += D6[p];
    }

    // for(int i = 0 ; i < NUMS ; i++ )// Find average key depth of tree
    // { 
       
    //     cout <<D5[i]<< ", ";
    // }
    // cout<<endl;

    ADS5 = dsum5 / NUMS;
    cout << "Average Key Depth for AVL Tree = " << ADS5 <<endl;
    cout<<endl; // --------------------------------------------------------------------------------

    // for(int i = 0 ; i < NUMS ; i++ )// Find average key depth of tree
    // { 
       
    //     cout <<D6[i]<< ", ";
    // }
    // cout<<endl;

    ADS6 = dsum6 / NUMS;
    cout << "Average Key Depth for BST  = " << ADS6 <<endl;
    cout<<endl; // --------------------------------------------------------------------------------

    for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T1. 
    { 
        //D1[p]=AVLT1.depth(randArray[p]);
        D1[p]=AVLT1.depth(randArray2[p]);
        dsum1 += D1[p];
    }

    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<D1[i]<< ", ";
    // }
    
    cout<<endl;
    ADS1 = dsum1 / NUMS;
    cout << "Mean depth of search for AVL Tree = " << ADS1 <<endl;
    cout<<endl;

     for( int p = 0 ; p < NUMS ; p++ ) // construct array with depth of search for T2. 
    { 
        //D2[p]=BST1.depth(randArray[p]);
        D2[p]=BST1.depth(randArray2[p]);
        dsum2 += D2[p];
    }

    // for(int i = 0 ; i < NUMS ; i++ ){ //debugging  delete this 
       
    //     cout <<D2[i]<< ", ";
    // }

    cout<<endl;
    ADS2 = dsum2 / NUMS;
    cout << "Mean Depth of Search for BST = " << ADS2 <<endl;

    double min3=10000;   
    for(int i = 0; i < NUMS; i++){
        if(D1[i] < min3){
            min3 = D1[i];
        }
    }
    cout << "Minimum Depth of Search for AVL Tree = " << min3<<endl;

    double min4=10000;
    for(int i = 0; i < NUMS; i++){
        if(D2[i] < min4){
            min4 = D2[i];
        }
    }
 
    cout << "Minimum Depth of Search for BST = " << min4<<endl;
        double max3=0;

    for(int i = 0; i < NUMS; i++){
        if(D1[i] > max3){
            max3 = D1[i];
        }
    }
 
    cout << "Maximum Depth of Search for AVL Tree = " << max3<<endl;
    double max4=0;
    for(int i = 0; i < NUMS; i++){
        if(D2[i] > max4){
            max4 = D2[i];
        }
    }
 
    cout << "Maximum Depth of Search for BST = " << max4<<endl;
    cout<<endl;
    cout << "End of Experiment 2" << endl;
    return 0;
}
