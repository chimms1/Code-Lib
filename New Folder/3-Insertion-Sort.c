#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void InsertionSort(int A[],int n);

int main()
{
    int MainArray[MAXSIZE], InsertionArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(InsertionArray,MainArray,n);
                
    printf("\nInsertion Sort: \n");
    
    printArray(InsertionArray,n);
    InsertionSort(InsertionArray,n);
    printf("\n ==> Sorted:");
    printArray(InsertionArray,n);

    printf("\n----------\n");
}

//function to sort an integer Array A of size n using Insertion Sort
void InsertionSort(int A[],int n)
{
    int i,j,key;

    for(i=1;i<n;i++){

        key=A[i];
        j=i-1;

        while(j>=0 && key<A[j]){
            A[j+1] = A[j];
            j--;
        }

        A[j+1]=key;
    }
}