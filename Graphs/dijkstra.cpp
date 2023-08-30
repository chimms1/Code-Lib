#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<limits.h>

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

void DijkstraAlgorithm(vector<pair<int,int>> adj[],int n,int source,
vector<int> &distance,vector<int> &pi)
{
    // Initialize
    for(int i=0;i<n;i++)
    {
        distance.push_back(INT_MAX);
        pi.push_back(-1);
    }
    distance[source] = 0;
    
    set<int>S;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
    
    cout<<"\nNew set size: "<<S.size()<<endl;
    
    Q.push({distance[source],source});
    
    while(!Q.empty())
    {
        // select vertex u
        int u = Q.top().second;
        Q.pop();
        
        S.insert(u);

        // Relax all edges that go to u
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].first;
            
            // if v.d > u.d + w(u,v)
            if(distance[v] > (distance[u] + adj[u][i].second))
            {
                // v.d = u.d + w(u,v)
                distance[v] = distance[u] + adj[u][i].second;
                
                pi[v] = u;
                
                Q.push({distance[v],v});
            }
        }   
    }
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
    
    vector<int> dist;
    vector<int> pi;
    
    DijkstraAlgorithm(adj,n,0,dist,pi);
    
    cout<<"\nAfter Dijkstra's\n";
    
    cout<<"\n\nDistance array: \n ";
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<"\t";
    }
    cout<<"\n ";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
    }
    
    
    
    cout<<"\n\n\nPi array: \n ";
    for(int i=0;i<n;i++)
    {
        cout<<pi[i]<<"\t";
    }
    cout<<"\n ";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
    }
    
    
    cout<<"\n\nFind shortest path\n";
    cout<<"Enter source: 0\n";
    
    int destination;
    cout<<"Enter destination [0-"<<n-1<<"]: ";
    cin>>destination;
    
    int sumdist = 0;
    stack<int>path;
    
    int j=destination;
    
    while(j>=0)
    {
        path.push(j);
        sumdist += dist[j];
        j = pi[j];
        
    }
    
    cout<<"\n Shortest path from 0 to "<<destination<<":\n";
    while(path.size()>1)
    {
        cout<<path.top()<<" -> ";
        path.pop();
    }
    cout<<path.top()<<"\nPath cost: "<<sumdist<<"\n\n";
    path.pop();
    
}