#include<iostream>

using namespace std;



int main()
{
    class A
    {
        public:
        A()
        {
            cout<<"YOOYOYOYYO A\n";
        }
        virtual void hello()=0;
    };

    class B:public A
    {
        public:
        // int hello()
        // {
        //     return 2;
        // }
        void hello()
        {
            cout<<"PURURURURUUR Virtualo\n";
        }
    };

    B* ptr;
    B ob2;

    ptr = &ob2;
    ptr->hello();





}