#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void MergeSort(int A[],int l,int r);
void Merge(int A[],int s1,int e1,int s2,int e2);

int main()
{
    int MainArray[MAXSIZE], MergeArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(MergeArray,MainArray,n);
                
    printf("\nMerge Sort: \n");
    
    printArray(MergeArray,n);
    MergeSort(MergeArray,0,n-1);
    printf("\n ==> Sorted:");
    printArray(MergeArray,n);

    printf("\n----------\n");
}


//function to merge two increasing sorted sub Arrays A[s1,s1+1,...,e1] and A[e1+1=s2,s2+1,...,e2]
void Merge(int A[],int s1,int e1,int s2,int e2)
{
    /*

    Main Array is virtually being made into 2 sub Arrays left and right: 
    
    s and e are notations for starting and ending :)

    s1 is the index of first element (Actually of both main Array and left sub Array)
    e1 is the index of the last element of the left sub Array

    s2 is the index of the first element of the right sub Array
    e2 is the index of last element (Actually of both main Array and right sub Array)
    
    */

   int *temp,k,i,j;

   // Allocating an Auxillary Array of Equal size of the Main Array
    temp=(int*)malloc((e2-s1+1)*sizeof(int));

    i=s1;  // initializing i to the beginning of left sub Array
    j=s2;  // initializing j to the beginning of the right sub Array

    // Running the loop for all the elements of Array from 0 to e2
    // untill anyone or both the sub arrays are completed
    for(k=0;i<=e1 && j<=e2;k++){

        // For loop runs till i and j reach the end of their respective sub Arrays
            
        if(A[i] < A[j]){

            // Insert the smaller element in temp Array
            temp[k] = A[i];
            i++;  // Take i to the next element
        }

        else if(A[j] < A[i]){

            // Insert the smaller element in temp Array
            temp[k] = A[j];
            j++;  // Take j to the next element

        }
    }// End of for loop
    
    // Once either of the sub Array is finished, the for loop breaks
    // according to the given conditions
        
    /* 
    Since one of the Sub Array is finished,
    we will insert remaining elements of the other sub Array
    into temp Array directly as they are already in sorted order
    */


    while(j<=e2){
    
        temp[k] = A[j];

        k++;
        j++;

    }

    while(i<=e1){
    
        temp[k] = A[i];

        k++;
        i++;

    }

    // Copy elements from temp Array to the Main Array
    for(k=0, i=s1; i<=e2 ;k++,i++){
        A[i] = temp[k];
    }

}

//function to sort an integer Array A of size n using Merge Sort from index left to right
void MergeSort(int A[],int l,int r)
{
    int m;

    // l and r become equal when they meet at the center
    if(l<r){
        
        m=(l+r)/2;  // to divide Array index into two equal partitions

        MergeSort(A,l,m);  // Sending the left sub Array A[l...... m,m+1 ......r]
        MergeSort(A,m+1,r);  // Sending the right sub Array
        Merge(A,l,m,m+1,r);  // Merging the sub Arrays A[l....m] and A[m+1....r]

    }
}