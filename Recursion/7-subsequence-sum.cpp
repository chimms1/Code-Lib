#include<iostream>
#include<vector>
using namespace std;

void AllSubsequence(int i, vector<int>ans,vector<int>A,int ssum,int k)
{
    if(i>=A.size())
    {
        if (ssum == k)
        {
            for(int k = 0;k<ans.size();k++)
            {
                cout<<ans[k]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    ans.push_back(A[i]);
    ssum += A[i];
    AllSubsequence(i+1,ans,A,ssum,k);
    
    ans.erase(ans.end()-1);
    ssum -= A[i];
    
    AllSubsequence(i+1,ans,A,ssum,k);
}

int main()
{
    vector<int>A = {1,2,1};
    int k = 2;
    AllSubsequence(0,{},A,0,k);
}