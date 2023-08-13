#include<iostream>
#include<vector>
#include<queue>
#define INF INT32_MAX

using namespace std;

vector<int> dijkstra(vector<pair<int,int>> adj[],int V, int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> prq;

    vector<int> dist(V);
    
    for(int i=0;i<V;i++)
    {
        dist[i] = INF;
    }

    dist[S] = 0;
    prq.push({0,S});

    while(!prq.empty())
    {
        int dis = prq.top().first;
        int node = prq.top().second;

        
    }
}

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

    int V = n;
    vector<int> distances = dijkstra(adj,V,1);  

}