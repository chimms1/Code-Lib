#include<bits/stdc++.h>

using namespace std;

int main()
{
    string S1 = "abcdsbbcd";
    string S2 = "ckasdbjbk";

    uint len1 = S1.length();
    uint len2 = S2.length();

    // int *LCS = new int[(len1+1)*(len2+1)];

    int LCS[len1+1][len2+1];


    // Intiliaze the LCS Table
    for(int i=0;i<len1+1;i++)
    {
        LCS[i][0] = 0;
    }

    for(int j=0;j<len2+1;j++)
    {
        LCS[0][j] = 0;
    }

    // Start Algorithm
    for(int i=1;i<len1+1;i++)
    {
        for(int j=1;j<len2+1;j++)
        {
            if(S1[i-1] == S2[j-1])
                LCS[i][j] = 1+ LCS[i-1][j-1];
                
            else
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    
    cout<<S1;
    cout<<"\n-------\n";
    cout<<S2;
    cout<<"\n-------\n";
    cout<<"Length of Longest Common Subsequence : "<<LCS[len1][len2]<<endl;
}