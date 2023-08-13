#include<iostream>
using namespace std;

class A
{
    int arr[3];

    public:
    A()
    {
        arr[0]=0;
        arr[1]=0;
        arr[2]=0;
    }

    // Overloading Subscript Operator
    int operator[](int i)
    {
        return arr[i];
    }

    // Overloading Subscript Operator
    int &operator[](int x)
    {
        return arr[x];
    }

};// End of class A