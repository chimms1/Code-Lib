// Unit weighted Graph using adjacency list: array of vectors
// uses O(2E) space

// #include<bits/stdc++.h>


/*
9 9
1 2
1 6
2 3
2 4
6 7
6 9
4 5
7 8
5 8
*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<int> BFS(vector<int> adj[],int n, int source)
{
    vector<int> bfs_traversal;

    // Initialize
    vector<int> visited(n+1,0);
    queue<int> q;

    visited[source] = 1;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        

        for(int i=0;i<adj[u].size();i++)
        {   
            if(visited[adj[u][i]]==0)
            {
                q.push(adj[u][i]);
                visited[adj[u][i]] = 1;
            }
        }
        bfs_traversal.push_back(u);
    }

    return bfs_traversal;
}

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
        for(int j=0;j<adj[i].size()-1;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> bfs_result = BFS(adj,n,1);

    for(int i=0;i<n;i++)
    {
        cout<<bfs_result[i]<<" ";
    }
    cout<<endl;
}