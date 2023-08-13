#include<iostream>

using namespace std;

int main()
{
    int a=1;
    int res = (++a)*(a++);
    cout<<res<<endl;
    return 0;
}