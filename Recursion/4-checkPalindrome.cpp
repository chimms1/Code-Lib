#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s,int l, int r,bool &check)
{
    if(l>=r)
    {
        check = true;
    }
    else if(s[l]==s[r])
    {
        isPalindrome(s,l+1,r-1,check);
    }
    return check;
}

int main()
{
    string s;
    
    getline(cin,s);
    
    cout<<s<<endl;
    
    bool check = false;
    
    check = isPalindrome(s,0,s.size()-1,check);
    
    cout<<"Given string is palindrome = "<<check<<endl;
}