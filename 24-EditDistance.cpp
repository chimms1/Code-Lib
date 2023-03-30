#include<bits/stdc++.h>
using namespace std;

int main()
{
    string one = "apiskal";
    string two = "vishal";

    int len1 = one.length()+1;
    int len2 = two.length()+1;


    int DP[len1][len2];

    for(int i= 0;i<len2;i++)
    {
        DP[i][0] = i;
    }

    for(int i=0;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(one[i] == two[j])
            {
                DP[i][j] = DP[i-1][j-1];
            }
            else
            {
                int x = DP[i-1][j];
                int y = DP[i][j-1];
                int z = DP[i-1][j-1];

                int m = min(x,y,z);

                DP[i][j] = m+1;
            }
        }
    }

    cout<<DP[len1][len2];

} 
