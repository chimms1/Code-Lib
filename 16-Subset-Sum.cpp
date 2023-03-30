#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {2,3,5,7};

    int n = sizeof(A)/sizeof(int);

    int sum = 9;

    int SS[n+1][sum+1];


    for(int i=0;i<=sum;i++)
    {
        SS[0][i] = 0;
    }
    for(int j=0;j<=n;j++)
    {
        SS[j][0] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(SS[i-1][j]==1)
            {
                SS[i][j]=1;
            }
            else if (A[i-1]>j)
            {
                SS[i][j] = 0;
            }
            else{
                SS[i][j] = SS[i-1][j-A[i]];
            }
        }
    }

    cout<<SS[n][sum];

}