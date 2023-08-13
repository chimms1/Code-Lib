// Weighted Graph using adjacency list: array of vectors

/*
5 6
1 2 5
3 2 96
1 4 10
5 3 14
4 5 12
1 5 9
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    // vector<int> adj[n+1];
    vector<pair<int,int>> adj[n+1]; // for weighted graph

    // cout<<sizeof(adj)<<endl;

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        adj[u].push_back(pair(v,w));
        adj[v].push_back(pair(u,w));
    }

    cout<<adj->size()<<endl;

    for(int i=1;i<n+1;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j].first<<","<<adj[i][j].second<<"\t";
        }
        cout<<endl;
    }
}