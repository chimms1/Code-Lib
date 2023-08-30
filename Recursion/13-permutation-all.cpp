#include<iostream>
#include<vector>
#include<map>

using namespace std;

void AllPermutation(vector<int>A,map<int,int>marked,vector<int> temp,vector<vector<int>>&answer)
{
    if(temp.size()>=A.size())
    {
        answer.push_back(temp);
        return;
    }
    
    for(int ind=0;ind<A.size();ind++)
    {
        if(marked[ind]==0)
        {
            marked[ind]=1;
            temp.push_back(A[ind]);
            AllPermutation(A,marked,temp,answer);
            temp.pop_back();
            marked[ind]=0;
        }
    }
}

int main()
{
    vector<int>candidates = {1,2,3};
    int target = 7;
    
    vector<vector<int>>answer;
    map<int,int>mark;
    AllPermutation(candidates,mark,{},answer);
    
    for(auto it:answer)
    {
        for(auto it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}