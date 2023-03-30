#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {2,3,5,7};

    int n = sizeof(A)/sizeof(int);

    int DP[n][n];

    for(int j=0;j<n;j++)
    {
        DP[n-1][j] = A[j];
    }

    for(int i = n-2;i<=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            DP[i][j] = min(DP[i+1][j],DP[i+1][j+1]);
        }
    }

    int query[] = {1,3};

    cout<<DP[n-(query[1]-query[0]-1)][query[0]];
}
