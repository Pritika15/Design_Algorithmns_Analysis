#include <bits/stdc++.h>
using namespace std;
bool bfs(int rGraph[301][301], int s, int t, int parent[], int V)
{
    bool visited[V+1]; 
    memset(visited, 0, sizeof(visited)); 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=1; v<=V; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
    return (visited[t] == true); 
} 

int fordFulkerson(int graph[301][301], int s, int t, int V) 
{ 
    int u, v; 
    int rGraph[301][301];
    for (u = 0; u <= V; u++) 
        for (v = 0; v <= V; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[V+1];  // This array is filled by BFS and to store path 
  
    int max_flow = 0;  // There is no flow initially 
    while (bfs(rGraph, s, t, parent, V)) 
    {
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
        max_flow += path_flow; 
    } 
    return max_flow; 
} 
int main() {
    int n,m,a,b,c,t;
    cin>>n>>m;
    int graph[301][301];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout <<fordFulkerson(graph, a, b, n)<<endl; 
    }
	return 0;
}