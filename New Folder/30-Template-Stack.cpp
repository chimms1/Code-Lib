#include<iostream>
#define MAXSIZE 5
using namespace std;

// Template class for Stack Data Structure
template<class X>
class stack
{
private:

    int top;    // Top of the Stack object
    int n;  // Size of the Stack
    X *A;  // Array

public:
    // Default Parameterized Constructor
    stack(int k=MAXSIZE)
    {
        top=-1; // Initialize Stack Top to 0
        n=k;    // Size of Array
        A=new X[n]; // Allocate an Array of size n
    }

    // Function Returns 1 IF Stack Empty ELSE 0
    int isEmpty()
    {
        // If Stack is Empty then top=-1
        // return 1
        if(top==-1)
            return 1;
        
        // Else
        return 0;
    }

    // Function Returns 1 IF Stack Full ELSE 0
    int isFull()
    {
        // If Stack is Full then top=size-1
        // return 1
        if(top==n-1)
            return 1;
        
        // Else
        return 0;
    }

    // Function to Push Element on Stack
    void push(X element)
    {
        // Check if Stack is Full
        if(isFull())
        {
            cout<<"\n  => Stack Overflow <=\n";
            cout<<"\n  - Push Unsuccessful -\n";
            return;
        }
        // Else
        top++;  // Increment top
        A[top]=element; // Add Element to Stack
        cout<<"\n  - Push Successful -\n";
    }

    // Function to Pop Element from Stack and Return it
    X pop()
    {
        // Check if Stack is Empty
        if(isEmpty())
        {
            cout<<"\n  => Stack Underflow <=\n";
            cout<<"\n  - Pop Unsuccessful -\n";
            return NULL;
        }
        // Else
        X data=A[top];  // Get Element from Stack
        top--;  // Decrement top
        cout<<"\n  - Pop Successful -\n";
        // Return popped Element
        return data;
    }

    // Function to Display Stack
    void display()
    {
        // If Stack is not Empty
        if(!isEmpty()){
            cout<<"\n---Stack: ";
            cout<<A[top];
            for(int i=top-1;i>=0;i--)
            {
                cout<<"\n        ->  "<<A[i];
            }
        }
        // If Stack is Empty
        else
            cout<<"\n  => Stack is Empty <=\n";
    }

    // Function return Top Element of the Stack
    X peek()
    {
        return A[top];
    }


};// End of Class Stack

// Template Function for Menu in main()
template<class X>
void MainDisplay(X stk,int c1,int c2)
{
}

int main()
{
    stack <int>s1;  // Stack s1 of integer elements
    stack <string>s2;    // Stack s2 of string elements

    int choice1;  // choice in menu1
    int choice2;  // choice in menu2

    int temp1;
    string temp2;

    while(1){

        cout<<"\n -- Select Stack --\n";
        cout<<"\n  > Integer Stack - 1\n  > String Stack - 2\n";
        cout<<"  => Enter your Choice: ";
        cin>>choice2;

        if(choice2==1||choice2==2)
        {
            cout<<"\n\n     --- Menu ---     \n  > Push - 1\n  > Pop - 2\n  > Display - 3\n  > Peek - 4\n  > Exit - 5\n";
            cout<<"  => Enter your Choice: ";
            cin>>choice1;
            
            switch(choice1){
            case 1: if(choice2==2){
                        cout<<"  => Enter a String to Push in Stack: ";
                        cin>>temp2;
                        s2.push(temp2);
                        break;
                    }
                    cout<<"  => Enter an Integer to Push in Stack: ";
                    cin>>temp1;
                    s1.push(temp1);
                    break;
            case 2: if(choice2==2){
                        temp2=s2.pop();
                        cout<<"  => Element Popped from Stack: "<<temp2<<endl;
                        break;
                    }
                    temp1=s1.pop();
                    cout<<"  => Element Popped from Stack: "<<temp1<<endl;
                    break;
            case 3: if(choice2==2){
                        s2.display();
                    }
                    s1.display();                    
                    break;
            case 4: if(choice2==2){
                        temp2=s2.peek();
                        cout<<"  => Top of Stack: "<<temp2<<endl;
                        break;
                    }
                    temp1=s1.peek();
                    cout<<"  => Top of Stack: "<<temp1<<endl;
                    break;
            case 5: exit(0);
                    break;
            default:cout<<"   === Invalid Selection ===   \n";
                    break;
            }
        }
        else
            cout<<"\n  => Enter Valid Choice\n";

        
    }//End of While loop
}//End of Main