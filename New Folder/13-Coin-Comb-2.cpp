#include<bits/stdc++.h>

using namespace std;

int counta = 0;

void answer(int C[],int n,int sum)
{
    static int huh = 0;

    cout<<huh<<"- - ";

    for(int i=0;i<n;i++)
    {
        cout<<C[i]<<" ";
    }
    cout<<"\n";

    huh++;
    if(n<=0)
    {
        return;
    }

    if(sum<0)
    {
        return;
    }

    if(sum==0)
    {
        counta++;
        return;
    }


    answer(C,n-1,sum); // Consider the current element
    answer(C,n,sum-C[n-1]); // Dnot consider

}


int main()
{
    int C[] = {2,3,5};
    int sum = 5;

    int n = sizeof(C)/sizeof(int);

    // cout<<n;
    answer(C,n,sum);
    cout<<counta<<endl;
}