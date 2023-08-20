#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 10


//function to swap value of two integer variables
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

void BubbleSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
        }
    }
}

int getMinIndex(int A[],int index,int n)
{
    int min = A[index];
    int minindex = index;

    for(int j=index+1;j<n;j++)
    {
        if(min>A[j])
        {
            min = A[j];
            minindex = j;
        }
    }
    return minindex;
}


void SelectionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int here = getMinIndex(A,i,n);

        if(i!=here)
            swap(&A[i],&A[here]);
    }
}

void InsertionSort(int A[],int n)
{
    for(int j=1;j<n;j++)
    {
        int key = A[j];

        int i = j-1;

        while(i>=0 && A[i]>key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void Merge(int A[],int l1,int r1,int l2,int r2)
{
    // Auxillary array
    int B[r2-l1+1];

    int i=l1;
    int j=l2;

    int k=0;

    while(i<=r1 && j<=r2)
    {
        if(A[i]<A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while(i<=r1)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=r2)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    i = l1;
    k = 0;

    while(i<=r2)
    {
        A[i] = B[k];
        k++;
        i++;
    }
}

void MergeSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;

        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,q+1,r);
    }
}

int Partition(int A[],int low, int high)
{
    //  4 6 1 9 8 7
    //      j i
    //
    //  4 6 9 1 8 7, does not happen as i>j
    //

    // pivot =  anything except high -> j, where j starts from high
    // pivot = high -> j+1, where j starts from high-1


    int pivotindex = low;
    int pivot = A[pivotindex];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(A[i]<=pivot && i<=high)
        {
            i++;
        }
        while(A[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
    }
    printf("low: %d\ti: %d\tj: %d\n",low,i,j);
    swap(&A[pivotindex],&A[j]);

    return j;
}

void QuickSort(int A[],int low, int high)
{
    if(low<high)
    {
        int p = Partition(A,low,high);
        QuickSort(A,low,p-1);
        QuickSort(A,p+1,high);
    }
}


int main()
{
    int MainArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    QuickSort(MainArray,0,n-1);
    printf("\n ==> Sorted:");
    printArray(MainArray,n);
}

