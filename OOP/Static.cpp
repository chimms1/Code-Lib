#include<iostream>
using namespace std;

template<class X>
void fun(X ob)
{
    ob.showX();
}

class temp
{
    int x;
    static int y;

public:
    void setX(int a)
    {
        x=a;
    }

    static void showY(float hi=0.0)
    {
        //showNothing();
        //ob.showNothing();
        int huh=0;
        huh++;
        cout<<"\n Huh : "<<huh<<endl;
        y++;
        cout<<"\n y++";
        cout<<"\n Static Member Y = "<<&y<<endl;
        cout<<"\n Static Member Y = "<<y<<endl;
        // cout<<"\n Other Member X = "<<this.x<<endl;
    }

    void showNothing()
    {
        cout<<"here";
    }

    void showX()
    {
        cout<<"\n Data Member X = "<<x<<endl;
    }
};

int temp::y = 0;

int main()
{
    temp ob1,ob2;

    // ob1.showY();
    // ob2.showY();
    // temp::showY();
    
    temp::showY();

    ob1.setX(10);
    //ob1.showX();
    fun(ob1);
    //ob1.showY(ob1);
    ob1.showY();
    ob2.setX(100);
    ob2.showX();
    //ob2.showY(ob1);
    ob2.showY();

    temp::showY();
}