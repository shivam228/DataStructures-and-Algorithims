#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(int adj[5][5], int u, int v) 
{ 
    adj[u][v] = 1; 
    adj[v][u] = 1; 
} 


int main() 
{ 
    int v = 5; 
    int  adj[5][5];
    for (int i = 0; i < 5; ++i) 
    { 
        for (int x=0;x<5;x++) 
        {
        	adj[i][x] = 0;
		}
	}
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4);  
    for (int i = 0; i < 5; ++i) 
    { 
        for (int x=0;x<5;x++) 
           cout << adj[i][x]<<" "; 
        cout<<("\n"); 
    } 
    
    return 0; 
} 
