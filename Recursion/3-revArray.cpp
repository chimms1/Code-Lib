#include<iostream>

using namespace std;

void revArray(int A[],int l, int r)
{
    if(l>=r)
        return;
    
    revArray(A,l+1,r-1);
    swap(A[l],A[r]);
}

int main()
{
    int A[] = {1,2,3,4,5,6};
    int n = 6;
    
    revArray(A,0,n-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\t";        
    }
    cout<<endl;
}