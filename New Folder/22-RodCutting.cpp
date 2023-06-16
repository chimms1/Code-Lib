#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {2,3,5,7};

    int n = sizeof(A)/sizeof(int);

    int DP[n];

    DP[0] = 0;
    DP[1] = 0;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            DP[i] = max(DP[i],j*(i-j),j*DP[i-j]);
        }
    }


} 
