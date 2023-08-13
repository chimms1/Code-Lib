//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    // Working: Take top element out, then remove all elements greater than it into another stack
    // put that element back and then other elements
    // Doing this recursively for all the elements will sort the stack
    
       // If empty then return
    if (s.empty())
        return;
     
    int topwala = s.top();
    s.pop();
    
    // Dirty recursive call to member function
    sort();
     
    stack<int> tempStack;
    
    // Put all elements greater than x in tempstack
    while (!s.empty() && s.top() > topwala) {
        tempStack.push(s.top());
        s.pop();
    }
     
    // Put the old top back
    s.push(topwala);
    
     
    // Move all elements to the main stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
    
} 
