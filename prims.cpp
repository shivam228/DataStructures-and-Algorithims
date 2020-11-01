#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define V 9

void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 
    bool vis[V];   
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
    	for (int j = 0; j < V; j++)
    	{
    		if(graph[i][j]!=0)
    		{
    			adj[i].push_back(j);
			}
		}
	}
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, vis[i] = false; 
  
    dist[src] = 0; 
   
    for (int count = 0; count < V - 1; count++) 
	{ 
    int min = INT_MAX;
    int min_index;
        for (int v = 0; v < V; v++) 
        {
        if (vis[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v;
        }
        vis[min_index] = true; 
        for (int v = 0; v < adj[min_index].size(); v++) 
        {
            if (vis[adj[min_index][v]]==false && graph[min_index][adj[min_index][v]] < dist[adj[min_index][v]]) 
                dist[adj[min_index][v]] = graph[min_index][adj[min_index][v]]; 
            }
    } 
    int sum =0;
        for (int i = 0; i < V; i++) 
        {
        	sum = sum + dist[i];
		}
     cout<<"MST cost is"<<" "<<sum;
}

int main() 
{ 
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}  
  
