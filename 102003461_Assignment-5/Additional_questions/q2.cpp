#include <bits/stdc++.h>
using namespace std;
#define MAX 80
int V;
int bfs(int rGraph[MAX][MAX], int s, int t, int parent[])
{
    bool visited[V+1];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

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
                if(v==t)return true;
            }
        }
    }

    return false;
}
void dfs(int rGraph[MAX][MAX], int s, string &visited)
{
    visited[s] = '1';
    for (int i = 1; i <= V; i++)
       if (rGraph[s][i] && visited[i]!='1')
           dfs(rGraph, i, visited);
}

void minCut(int graph[MAX][MAX], int s, int t,int &flow,string &visited,string temp,int len)
{
    int u, v;
  //  cout<<temp<<endl;
    int rGraph[MAX][MAX]={0};
    for (u = 1; u <= V; u++)
        for (v = 1; v <= V; v++)
             {
                 if(u==v)continue;
                 if(len>=u && len>=v){
                    if(temp[u]=='1' && temp[v]=='0'){
                        rGraph[s][t]+=graph[u][v];
                    }
                    else if(temp[u]=='0' && temp[v]=='1'){
                        rGraph[t][s]+=graph[u][v];
                    }
                    else if(temp[u]=='x')rGraph[u][v]+=graph[u][v];
                 }
                 else if(len>=u){
                    if(temp[u]=='1')rGraph[s][v]+=graph[u][v];
                    else rGraph[t][v]+=graph[u][v];
                 }
                 else if(len>=v){
                    if(temp[v]=='1')rGraph[u][s]+=graph[u][v];
                    else rGraph[u][t]+=graph[u][v];
                 }
                 else rGraph[u][v]+=graph[u][v];

             }

    int parent[V+1];

    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        flow+=path_flow;
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    for(int i=0;i<=V;i++)visited+='0';
    dfs(rGraph, s, visited);
    for(int i=1;i<=len;i++)if(temp[i]!='x')visited[i]=temp[i];

//visited vertices are on source side
    return;
}

int main()
{
    int n,m,k,s,t,graph[MAX][MAX]={0};
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    V=n;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]+=w;
    }
    priority_queue<pair<int,pair<int,string> >, vector<pair<int,pair<int,string> > >, greater<pair<int,pair<int,string> > > > minpq;
    string visited,x;
    int flow=0;
    for(int i=0;i<=n;i++)x+='x';

    minCut(graph,s,t,flow,visited,x,x.size()-1);
    minpq.push(make_pair(flow,make_pair(1,visited)));
    for(int x=1;x<k;x++){
        string vis,temp;
        int level;
        flow=minpq.top().first;
        temp=minpq.top().second.second;
        level=minpq.top().second.first;
       // cout<<flow<<endl;
        minpq.pop();
       // cout<<temp<<" "<<flow<<endl;
        for(int i=temp.size()-1;i>=level;i--){
            if(i==s || i==t)continue;
            string vis;
            flow=0;
            if(temp[i]=='1')temp[i]='0';
            else temp[i]='1';
            minCut(graph,s,t,flow,vis,temp,i);
            minpq.push(make_pair(flow,make_pair(i+1,vis)));

        }
    }
    printf("%d",minpq.top().first);
    return 0;
}
