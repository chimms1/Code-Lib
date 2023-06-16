// Unit weighted Graph using adjacency list: array of vectors
// uses O(2E) space
/*
5 6
1 2
3 2
1 4
5 3
4 5
1 5
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    vector<int> adj[n+1];
    // vector<pair<int,int>> adj[n+1]; // for weighted graph

    // cout<<sizeof(adj)<<endl;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<adj->size()<<endl;

    for(int i=1;i<n+1;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    

}