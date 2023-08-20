#include<iostream>
#include<vector>
using namespace std;

void CombinationSum(int i, vector<int>A, int k, vector<int>temp,vector<vector<int>>&answer)
{
    // base case
    if(k<0)
    {
        return;
    }
    if(i>=A.size())
    {
        if(k==0)
        {
            answer.push_back(temp);
            return;
        }
        return;
    }
    
    // instead you can take if(A[i]<target) only then target-A[i]
    
    k-=A[i];
    temp.push_back(A[i]);
    CombinationSum(i,A,k,temp,answer);
    
    k+=A[i];
    temp.pop_back();
    CombinationSum(i+1,A,k,temp,answer);
}

int main()
{
    vector<int>candidates = {2,3,5,7};
    int target = 7;
    
    vector<vector<int>>answer;

    CombinationSum(0, candidates, target, {}, answer);
    
    for(auto it:answer)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}