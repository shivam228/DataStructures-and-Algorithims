#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[5]; 
queue<int> q;
void addEdge(vector<int> adj1[], int u, int v) 
{ 
    adj1[u].push_back(v); 
    adj1[v].push_back(u); 
} 

void bfs(bool vis[5],int v)
{
	vis[v]  = true;
	q.push(v);
	while(q.size()>0)
	{
		int z = q.front();
		q.pop();
		cout<<z;
	for (int x=0;x<adj[z].size();x++)
	{
		if(vis[adj[z][x]]==false)
	 	{
	 		vis[adj[z][x]] = true;
	 		q.push(adj[z][x]);
		 }
	}
	}
	 
}
int main() 
{ 
    
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    bool vis[5];
    for(int i =0;i<5;i++)
    {
    	vis[i] = false;
	}
    bfs(vis,0);
    
    
    return 0; 
} 
