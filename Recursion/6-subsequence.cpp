#include<iostream>
#include<vector>
using namespace std;

void AllSubsequence(int i, vector<int>ans,vector<int>A)
{
    if(i>=A.size())
    {
        for(int k = 0;k<ans.size();k++)
        {
            cout<<ans[k]<<" ";
        }
        cout<<endl;
        
        return;
    }
    
    ans.push_back(A[i]);
    AllSubsequence(i+1,ans,A);
    
    ans.erase(ans.end()-1);
    AllSubsequence(i+1,ans,A);
}

int main()
{
    vector<int>A = {3,1,2};
    
    AllSubsequence(0,{},A);
}