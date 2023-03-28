#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to fill Array A with Random integers
void fillRandom(int A[],int n)
{
	int i;
	srand(time(NULL));
    
	for(i=0;i<n;i++)
	{
		A[i]=rand()%1000;
	}
}

//Function to Copy integers of Array B to Array A
void copy(int A[],int B[],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		A[i]=B[i];
	}
}


//Function to Print Array Elements
void printArray(int A[],int n)
{
	int i;
	printf("\nArray elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
    printf("\n");
}