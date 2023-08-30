#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>

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

vector<vector<int>>* PrimAlgorithm(vector<vector<int>> adj[],int n)
{
    // Initialize
    vector<int> visited(n,0);
    visited[0] = 1;
    
    vector<vector<int>> answer;
    
    int summation = 0;
    
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> Q;
    
    Q.push({0,0,-1});
    
    
    while(!Q.empty())
    {
        int w = Q.top()[0];
        int node = Q.top()[1];
        int parent = Q.top()[2];
        
        Q.pop();
        
        if(visited[node])
            continue;
        
        visited[node]=1;
        summation+=w;
        
        for(auto it:adj[node])
        {
            if(!visited[it[1]])
            {
                Q.push({it[3],it[1],it[0]});
            }
        }
        
        if(parent!=-1)
        {
            answer.push_back({node,parent,w});
        }
    }
    
    
    
    
    
    
    return answer;
} 


int main()
{
    int n,m;

    cin>>n>>m;

    // vector<int> adj[n+1];
    vector<vector<int>> adj[n]; // for weighted graph

    // cout<<sizeof(adj)<<endl;

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        adj[v].push_back({v,u,w});
        adj[u].push_back({u,v,w});
    }

    cout<<"\n adj->size(): "<<adj->size()<<"\t n: "<<n<<endl<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(auto j:adj[i])
        {
            cout<<j[1]<<","<<j[2]<<"\t";
        }
        cout<<endl;
    }
    
    vector<vector<int>> *MST = PrimAlgorithm(adj,n);
    
    
    cout<<"\n\nMinimum Spanning Tree from Prim's Algorithm\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";

        // adj[i] is a vector, so indexing starts from 0
        for(auto j:MST[i])
        {
            cout<<j[1]<<","<<j[2]<<"\t";
        }
        cout<<endl;
    }
}