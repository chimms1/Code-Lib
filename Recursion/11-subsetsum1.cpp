#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void SubsetSum(int i, vector<int>A, int tempsum,vector<int>&answer)
{
    
    if(i>=A.size())
    {
        answer.push_back(tempsum);
        return;
    }
    
    tempsum+=A[i];
    SubsetSum(i+1,A,tempsum,answer);
    
    tempsum-=A[i];
    SubsetSum(i+1,A,tempsum,answer);
}

int main()
{
    vector<int>candidates = {2,3,5,7};
    int target = 7;
    
    vector<int>answer;
    
    SubsetSum(0,candidates,0,answer);
    
    sort(answer.begin(),answer.end());
    
    for(auto it:answer)
    {
        // for(auto it2:it)
        // {
        //     cout<<it2<<" ";
        // }
        cout<<it<<" "<<endl;
    }
}