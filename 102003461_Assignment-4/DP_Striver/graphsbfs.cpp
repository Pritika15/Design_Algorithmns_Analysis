#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=9,m=9;
	vector<int>adjList[n+1];
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	vector<int>visited(n+1,0);
	queue<int>q;
	q.push(1);
	visited[1]=1;
	while(!q.empty())
	{
		int temp=q.front();
		cout<<temp<<" ";
		q.pop();
		for(int i=0;i<temp.size();i++)
		{
			if(!visited[adjList[i]])
			{
				q.push(adjList[i]);
			}
		}
		
	}
	
}
