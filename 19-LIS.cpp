#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {5,11,3,15,30,25};

    int n = sizeof(A)/sizeof(int);

    int LIS[n];

    for(int i=0;i<n;i++)
    {
        LIS[i] = 1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && LIS[j]+1>LIS[i])
                LIS[i] = LIS[j]+1;
        }
    }

    cout<<max(LIS);
}