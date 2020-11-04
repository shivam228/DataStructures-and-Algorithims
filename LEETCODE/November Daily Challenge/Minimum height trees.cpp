class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        
        queue<int> q;
        vector<int> res;
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        vector<int> degree(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;
            degree[edges[i][0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
                q.push(i);
        }
        
        while(q.size()>0)
        {
            int z = q.size();
           res.clear();
            while(z--)
            {
            int x =q.front();
            q.pop();
                res.push_back(x);
            for(int y:adj[x])
            {
                degree[y]--;
                if(degree[y]==1)
                    q.push(y);
            }
            }
            
        }
        return res;
    }
};