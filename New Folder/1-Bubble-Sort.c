#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void swap(int *a,int *b);
void BubbleSort(int A[],int n);

int main()
{
    int MainArray[MAXSIZE], BubbleArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(BubbleArray,MainArray,n);
                
    printf("\nBubble Sort: \n");
    
    printArray(BubbleArray,n);
    BubbleSort(BubbleArray,n);
    printf("\n ==> Sorted:");
    printArray(BubbleArray,n);

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

//function to sort an integer Array A of size n using Bubble Sort
void BubbleSort(int A[],int n)
{
	int i,j;

	for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-i-2;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
            }
        }
    }
}