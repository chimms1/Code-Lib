#include<iostream>
using namespace std;

class complex
{
    int real;
    int imz;

    public:
        // Constructor Function
        complex(int x=0,int y=0)
        {
            real=x;
            imz=y;
        }

        // Function to set values of real and imz
        void setnumbers(int x,int y)
        {
            real=x;
            imz=y;
        }

        // Function to print a complex number
        void complex_print()
        {
            cout<<endl;
            if(imz>0)
                cout<<"\n  ==> "<<real<<" + "<<imz<<"i"<<endl;
            else if(imz<0)
                cout<<"\n  ==> "<<real<<" "<<imz<<"i"<<endl;
            else
                cout<<"\n  ==> "<<real<<" + "<<imz<<"i"<<endl;
        }

        /*
        // Operator Overloading to + two complex numbers
        complex operator+(complex ob)
        {
            complex temp;  //Temporary Object

            temp.real = ob.real + real;
            temp.imz = ob.imz + imz;

            return temp;
        }

        // Operator Overloading to - two complex numbers
        complex operator-(complex ob)
        {
            complex temp;  //Temporary Object

            temp.real = real - ob.real;
            temp.imz = imz - ob.imz;

            return temp;
        }

        // Operator Overloading to * two complex numbers
        complex operator*(complex ob)
        {
            complex temp;

            temp.imz = (imz * ob.real) + (real * ob.imz);
            temp.real = (real * ob.real) + (imz * ob.imz);

            return temp;
        }
        */

        // Operator Overloading to assign complex number objects
        complex operator=(complex ob)
        {
            real=ob.real;
            imz=ob.imz;

            return *this;
        }

        // Operator Overloading to Pre-increment a complex number
        complex operator++()
        {
            real++;
            imz++;

            return *this;
        }

        // Operator Overloading to Post-increment a complex number
        complex operator++(int x)
        {
            real++;
            imz++;

            return *this;
        }

        // Operator Overloading to shorthand-Increment with an integer
        complex operator+=(int x)
        {
            real=real+x;
            imz=imz+x;

            return *this;
        }

        // Operator Overloading to shorthand-Increment with a Complex Object
        complex operator+=(complex ob)
        {
            real=real+ob.real;
            imz=imz+ob.imz;

            return *this;
        }

        friend complex operator+(complex ob1,complex ob2);
        friend complex operator-(complex ob1,complex ob2);
        friend complex operator*(complex ob1,complex ob2);
        friend class A;
};

class A
{
    int a;

    public:

    int func()
    {
        
    }
};

// Operator Overloading to + two complex numbers using Friend function
complex operator+(complex ob1,complex ob2)
{
    complex temp;  //Temporary Object

    //cout<<"\n==Friend +\n";
    temp.real = ob1.real + ob2.real;
    temp.imz = ob1.imz + ob2.imz;
    return temp;
}

// Operator Overloading to - two complex numbers using Friend function
complex operator-(complex ob1,complex ob2)
{
    complex temp;  //Temporary Object

    //cout<<"\n==Friend -\n";
    temp.real = ob1.real - ob2.real;
    temp.imz = ob1.imz - ob2.imz;

    return temp;
}

// Operator Overloading to * two complex numbers using friend function
complex operator*(complex ob1,complex ob2)
{
    complex temp;

    //cout<<"\n==Friend *\n";
    temp.imz = (ob1.imz * ob2.real) + (ob1.real * ob2.imz);
    temp.real = (ob1.real * ob2.real) - (ob1.imz * ob2.imz);

    return temp;
}


int main()
{
    complex num1(5,5),num2(4,4);

    cout<<"\n Complex num1: \n";
    num1.complex_print();

    cout<<"\n Complex num2: \n";
    num2.complex_print();

    complex sum,dif,mul; //asgn,post,pre;

    sum=num1+num2;
    cout<<"\n num1 + num2 :";
    sum.complex_print();

    dif=num1-num2;
    cout<<"\n num1 - num2 :";
    dif.complex_print();
    

    mul=num1*num2;
    cout<<"\n num1 * num2 :";
    mul.complex_print();

    /*
    asgn=num1;
    cout<<"\n asgn = num1 :\n";
    asgn.complex_print();

    pre=++num1;
    cout<<"\n pre = num1 :\n";
    pre.complex_print();

    post=num1++;
    cout<<"\n post = num1 :\n";
    */

}