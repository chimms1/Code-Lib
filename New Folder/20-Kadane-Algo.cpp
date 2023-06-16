#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {2,3,5,7};

    int n = sizeof(A)/sizeof(int);

    int sum = 0;

    int maxsum = A[0];

    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        maxsum = max(sum,maxsum);

        if(sum<0)
            sum=0;
    } 
}
