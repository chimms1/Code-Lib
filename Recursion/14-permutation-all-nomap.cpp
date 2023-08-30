#include<iostream>
#include<vector>

using namespace std;

void AllPermutation(int i,vector<int>A,vector<int> temp,vector<vector<int>>&answer)
{
    if(i>=A.size())
    {
        answer.push_back(A);
        return;
    }
    
    for(int ind=i;ind<A.size();ind++)
    {
        swap(A[i],A[ind]);
        // temp.push_back(A[i]);
        AllPermutation(i+1,A,temp,answer);
        // temp.pop_back();
        swap(A[i],A[ind]);
    }
}

int main()
{
    vector<int>candidates = {1,3,2};
    int target = 7;
    
    vector<vector<int>>answer;

    AllPermutation(0,candidates,{},answer);
    
    for(auto it:answer)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}