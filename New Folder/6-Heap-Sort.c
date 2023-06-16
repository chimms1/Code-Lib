#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void swap(int *a,int *b);
void Max_Heapify(int A[],int n,int i);
void Build_Max_Heap(int A[],int n);
void HeapSort(int A[],int n);

int main()
{
    int MainArray[MAXSIZE], HeapArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(HeapArray,MainArray,n);
                
    printf("\nHeap Sort: \n");
    
    printArray(HeapArray,n);
    HeapSort(HeapArray,n);
    printf("\n ==> Sorted:");
    printArray(HeapArray,n);

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

void Max_Heapify(int A[],int n,int i)
{
    int largest,l,r;
    largest=i;
    l=2*i;
    r=2*i+1;

    if(l<n && A[l]>A[i]){
        largest=l;
    }
    else{
        largest=i;
    }

    if(r<n && A[r]>A[largest]){
        largest=r;
    }

    if(largest!=i){

        swap(&A[largest],&A[i]);
        
        Max_Heapify(A,n,largest);
    
    }
    
}

void Build_Max_Heap(int A[],int n)
{
    for(int i=n;i>=0;i--){
        Max_Heapify(A,n,i);
    }
}

void HeapSort(int A[],int n)
{
    Build_Max_Heap(A,n);
    
    for(int i=n-1;i>=0;i--){

        swap(&A[0],&A[i]);
        Max_Heapify(A,i,0);
        
    }
}