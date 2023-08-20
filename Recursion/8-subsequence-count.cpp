#include<iostream>
#include<vector>
using namespace std;

int AllSubsequence(int i, vector<int>ans,vector<int>A,int ssum,int k,int count)
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
            return 1;
        }
        return 0;
    }
    
    ans.push_back(A[i]);
    ssum += A[i];
    int l = AllSubsequence(i+1,ans,A,ssum,k,count);
    
    
    ans.erase(ans.end()-1);
    ssum -= A[i];
    
    int r = AllSubsequence(i+1,ans,A,ssum,k,count);
    
    return l+r;
}

int main()
{
    vector<int>A = {1,2,1};
    int k = 3;
    int temp = AllSubsequence(0,{},A,0,k,0);
    
    cout<<endl<<temp<<endl;
}