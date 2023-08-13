#include<bits/stdc++.h>

using namespace std;

class A
{
	int x;
	public:
	A()
	{
		cout<<"Hello from Base Constructor\n";
	}
	A(int a)
	{
		this->x = a;
		cout<<"Hello from parameter Base Constructor\n";
	}
	void hello()
	{
		cout<<"Hello from Base\n";
	}
	int getX()
	{
		return x;
	}
};

class B: public A
{
	int y;
	public:
	B(int c,int b):A(c)
	{
		this->y=b;
		cout<<"Hello from Derived Constructor\n";
	}
	void hello()
	{
		cout<<"Hello from Derived\n";
		cout<<"y: "<<y<<endl;
		cout<<"x: "<<getX()<<endl;
	}
};

int main()
{
	// A ob1;
	B ob2(5,10);

	// ob1.hello();
	ob2.hello();

	// ob2.A::hello();


	// A* ptr1 = &ob2;

	// ptr1->hello();

	// A::hello();	// Can be called with only pointer
}