#include<iostream>

using namespace std;

// i -> depth
int printFibo(int n,int i)
{
    if(n<=1) 
    {
        if(i==n) cout<<n<<endl;
        return n;
    }
    
    int last = printFibo(n-1,i-1);
    int slast = printFibo(n-2,i-1);
    
    int ans = last+slast;
    
    if(i==n) cout<<ans<<endl;
    
    return ans;
}

int main()
{
    int n=5;
    
    int k=printFibo(n,n);
    
    return 0;
}