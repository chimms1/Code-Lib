#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

/*
6 8
0 1 4
0 2 4
1 2 2
2 3 3
2 4 1
2 5 6
3 5 2
4 5 3
*/

void PrimsAlgorithm(vector<pair<int,int>> adj[], int n, vector<pair<int,int>> answer[])
{
    // cout<<"\n\nFrom function!!!\n";
    
    // Initialize
    vector<int> visited(n,0);
    // reverse()
    // visited[0] = 1;**************************************************************
    
    int summation = 0;
    
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> Q;
    
    Q.push({0,0,-1});
    
    while(!Q.empty())
    {
        int w = Q.top()[0];
        int node = Q.top()[1];
        int parent = Q.top()[2];
        
        Q.pop();
        
        if(visited[node]==1)
            continue;
        
        visited[node]=1;
        summation+=w;
        
        cout<<adj[node].size()<<endl;
        
        for(int i=0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i].first]!=1)
            {
                Q.push({adj[node][i].second,adj[node][i].first,node});
            }
        }
        
        if(parent!=-1)
        {
            answer[node].push_back({parent,w});
            answer[parent].push_back({node,w});
        }
    
    }
    cout<<"\n~~~~~~~~~~~~~~~"<<summation<<"~~~~~~~~~~~~~~~~~\n";
    
    for(auto it:visited)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,m;

    cin>>n>>m;

    // vector<int> adj[n+1];
    vector<pair<int,int>> adj[n]; // for weighted graph

    // cout<<sizeof(adj)<<endl;

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        adj[u].push_back(pair(v,w));
        adj[v].push_back(pair(u,w));
    }

    cout<<"\n adj->size(): "<<adj->size()<<"\t n: "<<n<<endl<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j].first<<","<<adj[i][j].second<<"\t";
        }
        cout<<endl;
    }
    
    
    vector<pair<int,int>> MST[n];
    PrimsAlgorithm(adj,n,MST);
    
    cout<<"\n\nMinimum Spanning Tree from Prim's Algorithm\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(int j=0;j<MST[i].size();j++)
        {
            cout<<MST[i][j].first<<","<<MST[i][j].second<<"\t";
        }
        // cout<<MST[i].size();
        cout<<endl;
    }
    
}