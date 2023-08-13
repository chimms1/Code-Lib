/*
5
69 120 280 300 420
299
*/

#include<iostream>
#include<vector>

using namespace std;

int BinarySearchRecursion(int low, int high, vector<int>nums, int key)
{
    int answer;

    if(low>high)
    {
        answer = -1;
        return answer;
    }

    int middle = (low+high)/2;

    if(nums[middle]==key)
    {
        answer = middle;
        // return middle;
    }

    else if(key<nums[middle])
    {
        answer = BinarySearchRecursion(low,middle-1,nums,key);
    }
    else if(key>nums[middle])
    {
        answer = BinarySearchRecursion(middle+1,high,nums,key);
    }

    return answer;
}


int Search(vector<int> nums, int key)
{
    int n = nums.size();

    int low = 0;
    int high = n-1;
    

    // int middle = (low+high)/2;

    int index = BinarySearchRecursion(low,high,nums,key);


    return index;
}



int main()
{
    int n;
    cin>>n;

    vector<int>nums;

    for(int i=0;i<n;i++)
    {
        int tempin;
        cin>>tempin;
        nums.push_back(tempin);
    }

    int key;
    cin>>key;

    cout<<endl<<endl;

    for(auto it:nums)
    {
        cout<<it<<" ";
    }

    int index = Search(nums,key);

    if(index==-1)
    {
        cout<<"\n\nkey not found\n";
    }
    else{
        cout<<"\n\nkey found at index "<<index<<endl;
    }

    


}