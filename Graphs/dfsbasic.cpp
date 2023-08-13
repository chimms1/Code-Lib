/*
8 8
1 2
1 3
2 5
2 6
3 4
3 7
7 8
4 8
*/


#include<iostream>
#include<vector>

using namespace std;

void DFS(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfs_traversal)
{
    visited[node] = 1;
    dfs_traversal.push_back(node);

    for(int i=0;i<adj[node].size();i++)
    {
        if(visited[adj[node][i]]==0)
        {
            DFS(adj[node][i],adj,visited,dfs_traversal);
        }
    }
}

vector<int> DFSofGraph(vector<int> adj[], int n, int source)
{
    vector<int> dfs_traversal;

    vector<int> visited(n,0);

    visited[source] = 1;

    DFS(source,adj,visited,dfs_traversal);

    return dfs_traversal;
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

    vector<int> dfs_result = DFSofGraph(adj,n,1);

    for(int i=0;i<n;i++)
    {
        cout<<dfs_result[i]<<" ";
    }
    cout<<endl;
}