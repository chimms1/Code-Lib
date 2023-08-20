#include<iostream>
#include<vector>
using namespace std;

bool AllSubsequence(int i, vector<int>ans,vector<int>A,int ssum,int k)
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
            return true;
        }
        return false;
    }
    
    ans.push_back(A[i]);
    ssum += A[i];
    if(AllSubsequence(i+1,ans,A,ssum,k))
    {
        return true;
    }
    
    ans.erase(ans.end()-1);
    ssum -= A[i];
    
    if(AllSubsequence(i+1,ans,A,ssum,k))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int>A = {1,2,1};
    int k = 3;
    bool temp = AllSubsequence(0,{},A,0,k);
}