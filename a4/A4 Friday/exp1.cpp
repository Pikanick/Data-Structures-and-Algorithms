#include <iostream>
#include <time.h>
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main()
{
    
    clock_t start, finish ;// used for getting the time. 
    double time_taken =0;
    int size=500000;
    int *A= new int[size];
    //int steps=100000;
    int *B= new int[size];
    //cout<<"Hi "<<endl;
    double time1[size], time2[size];
    //cout<<"hello hello"<<endl;
    double total1=0.0, total2=0.0, ave1=0.0, ave2=0.0;
    
   
    for(int i=0; i<size; i++)
    {
        A[i]=i;
        B[i]=i;
    }
    
    
    // Modified Loop 1
    //   for i from 0 to array_length by increments of 64
    //   access each element A[i], A[i+1], A[i+2], ... A[i+16].
 

    // cout<<"Loop 1 Time Taken: "<<time_taken<<endl;
    
    // Modified Loop 2
    //   for i from 0 to array_length by increments of 64
    //   access element B[i]
    int j=0;
    start = clock(); 
    for(int i=0; i<size; i+=64)// loop 2 from lab info
    {
        B[i]*=3;
        // finish = clock(); 
        // time_taken = elapsed_time(start,finish); 
        // time2[j]=time_taken;
        // total2+=time2[j];//total2=tb
        // j++;    
    }
    finish = clock(); 
    time_taken = elapsed_time(start,finish); 
        
     //ave2=total2*64/size;//=tmiss+thit
    //cout<<"Average time taken for an array access with a chache miss: "<<ave2<<endl;
    //cout<<total2<<endl;
    cout<<"Average time taken for loop 2: "<<time_taken<<endl;
    double tl2=time_taken;

    ave2=time_taken*64/size;//=tmiss+thit
    //cout<<"Average time taken for an array access with a chache miss: "<<ave2<<endl;
    //cout<<total2<<endl;
    cout<<"Average time taken for tmiss+thit "<<ave2<<endl;

    j=0;
    start = clock(); 
    for(int i=0; i<size; i+=64)// loop 1 from lab info
    {
        //start = clock(); 
        A[i]*=3;
        A[i+1]*=3;
        A[i+2]*=3;
        A[i+3]*=3;
        A[i+4]*=3;
        A[i+5]*=3;
        A[i+6]*=3;
        A[i+7]*=3;
        A[i+8]*=3;
        A[i+9]*=3;
        A[i+10]*=3;
        A[i+11]*=3;
        A[i+12]*=3;
        A[i+13]*=3;
        A[i+14]*=3;
        A[i+15]*=3;
        A[i+16]*=3;
        // finish = clock(); 
        // time_taken = elapsed_time(start,finish); 
        // time1[j]=time_taken;
        // total1+=time1[j];
        // j++;    
    }
    finish = clock(); 
    time_taken = elapsed_time(start,finish); 
    cout<<"Average time taken for loop 1: "<<time_taken<<endl;

    //cout<<total1<<" , "<<size<<" , "<<ave2<<endl;
    ave1=(time_taken*4/size)-(ave2/16);//=thit
    cout<<"Average time taken for an array access with a chache hit: "<<ave1<<endl;
    // double tmiss=((68*total2)-(4*total1))/size;
    double tmiss=(ave2)-(ave1);
    cout<<"Average time taken for an array access with a cache miss: "<<tmiss<<endl;



    //ave1=0.0625*(total1*64/size-ave2);
    // // cout<<total1<<" , "<<size<<" , "<<ave2<<endl;
    // // ave1=(total1*4/size)-(ave2/16);//=thit
    // // cout<<"Average time taken for an array access with a chache hit: "<<ave1<<endl;
    // double tmiss=((68*total2)-(4*total1))/size;
    // // double tmiss=((64*total2)/size)-(ave1);
    // // cout<<"Average time taken for an array access with a cache miss: "<<tmiss<<endl;

    // cout<<"Loop 2 Time Taken: "<<time_taken<<endl;

    // for(int i=0; i<steps; i++)
    // {
    //     start = clock(); 
    //     a[i]*=3;
    //     finish = clock(); 
    //     double time_taken = elapsed_time(start,finish); 
    // }
    // for(int i=0; i<steps; i+=16)
    // {
    //     start = clock(); 
    //     b[i]*=3;
    //     finish = clock(); 
    //     double time_taken = elapsed_time(start,finish); 
    // }

   

    //cout<<"hello"<<endl;
   
    return 0;


   

    
}