#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void swap(int *a,int *b);
int getArrayMinimumIndex(int A[],int n,int i);
void SelectionSort(int A[],int n);

int main()
{
    int MainArray[MAXSIZE], SelectionArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(SelectionArray,MainArray,n);
                
    printf("\nSelection Sort: \n");
    
    printArray(SelectionArray,n);
    SelectionSort(SelectionArray,n);
    printf("\n ==> Sorted:");
    printArray(SelectionArray,n);

    printf("\n----------\n"); 
}

//function to swap value of two integer variables
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

//Returns the Index of the Minimum valued element of an Array
int getArrayMinimumIndex(int A[],int n,int i)
{
    int min=A[i];
    int min_index=i;    //Variable with the value of minimum index

    for(int j=i+1;j<n;j++){
        if(A[j]<min){
            min=A[j];
            min_index=j;
        }
    }

    return(min_index);
}

//function to sort an integer Array A of size n using Selection Sort
void SelectionSort(int A[],int n)
{
    int index;

    for(int i=0;i<=n-1;i++){
        index=getArrayMinimumIndex(A,n,i);
        if(i!=index){
            swap(&A[i],&A[index]);
        }
    }
}