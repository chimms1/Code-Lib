#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0-Data.h"
#define MAXSIZE 20

void QuickSort(int A[],int l,int r);
int Partition(int A[],int p,int q);
void swap(int *a,int *b);

int main()
{
    int MainArray[MAXSIZE], QuickArray[MAXSIZE];
    int n=MAXSIZE;

    fillRandom(MainArray,n);
    printArray(MainArray,n);

    copy(QuickArray,MainArray,n);
                
    printf("\nQuick Sort: \n");
    
    printArray(QuickArray,n);
    QuickSort(QuickArray,0,n-1);
    printf("\n ==> Sorted:");
    printArray(QuickArray,n);

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

//partition function, that permutes the given  Array A from index p to q
//such that all elements before A[p] are smaller and all elements after A[p]
//are larger than A[p] within the range A[p,....,q]
int Partition(int A[],int p,int q)
{
    int Pivot = A[p];  // Storing Pivot value in a variable
    int i=p;  //Storing Pivot index in i

    //Now we are Sorting given Partition of Array such that 
    
    for(int j=p+1;j<=q;j++){
        
        if(A[j]<Pivot){
            i=i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[p],&A[i]);

    return(i);
}


//function to sort an integer Array A of size n using Quick Sort from index l to r
void QuickSort(int A[],int l,int r)
{
    int m;

    if(l<r){
        m=Partition(A,l,r);

        QuickSort(A,l,m-1); 
        QuickSort(A,m+1,r);

    }
}