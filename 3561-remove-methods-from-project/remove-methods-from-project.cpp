class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for(int next : adj[node])
        {
            if(!vis[next])
                dfs(next, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for(auto &edge : invocations)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        // suspicious methods
        vector<int> vis(n,0);
        dfs(k, adj, vis);

        // check if removable
        for(auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if(!vis[u] && vis[v])
            {
                vector<int> ans;

                for(int i=0;i<n;i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // remove suspicious methods
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};