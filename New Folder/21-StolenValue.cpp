#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {2,3,5,7};

    int n = sizeof(A)/sizeof(int);

    int DP[n+1];

    DP[0] = 0;

    DP[1] = A[1];

    for(int i=2;i<=n;i++)
    {
        DP[i] = max(DP[i-1],DP[i-2]+A[i]);
    }

}