#include<iostream>
#include<vector>

using namespace std;

void SubsetNoDuplicate(int i, vector<int>A, vector<int>temp,vector<vector<int>> &answer)
{
    answer.push_back(temp);
    
    for(int index=i;index<A.size();index++)
    {
        if(i!=index && A[i]==A[i-1])
            continue;
        temp.push_back(A[index]);
        SubsetNoDuplicate(index+1,A,temp,answer);
        temp.pop_back();
    }
}

int main()
{
    vector<int>candidates = {1,2,2,3};
    int target = 7;
    
    vector<vector<int>>answer;
    
    SubsetNoDuplicate(0,candidates,{},answer);
    
    for(auto it:answer)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}