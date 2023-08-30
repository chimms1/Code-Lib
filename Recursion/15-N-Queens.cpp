#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    for(int i=0;i<col;i++)
    {
            if(board[row][i]=='Q')
                return false;
    }
    
    int trow=row;
    int tcol=col;
    while (trow<n && tcol>=0)
    {
        if (board[trow][tcol]=='Q')
            return false;
        tcol--;
        trow++;
    }
    
    trow=row;
    tcol=col;
    while (trow>=0 && tcol>=0)
    {
        if (board[trow][tcol]=='Q')
            return false;
        tcol--;
        trow--;
    }
    
    return true;
}

void N_Queen(int col, int n, vector<string> board,vector<vector<string>> &answer)
{
    if(col>=n)
    {
        answer.push_back(board);
        return;
    }
    
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            N_Queen(col+1,n,board,answer);
            board[row][col] = '@';
        }
    }
}


int main()
{
    int n=4;
    
    string boardfill(n,'@');
    vector<vector<string>> answer(n);
    
    vector<string>board(n,boardfill);
    
    N_Queen(0,n,board,answer);
    
    for(auto it: answer)
    {
        for(auto it2: it)
        {
            cout<<it2<<endl;
        }
        cout<<endl<<endl;
    }
}