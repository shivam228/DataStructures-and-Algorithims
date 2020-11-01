#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj1[], int u, int v) 
{ 
    adj1[u].push_back(v); 
    adj1[v].push_back(u); 
} 


int main() 
{ 
    int v = 5; 
    vector<int> adj[v]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    
    for (int i = 0; i < v; ++i) 
    { 
        cout << "\n Adjacency list of vertex "
             << i << "\n head "; 
        for (int x=0;x<adj[i].size();x++) 
           cout << "-> " << adj[i][x]; 
        cout<<("\n"); 
    } 
    
    return 0; 
} 
