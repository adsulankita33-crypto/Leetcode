
class Solution {
public:
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit, fenwick;

    int getBit(char c) {
        return 1 << (c - 'a');
    }

    void updateBIT(int idx, int val) {
        while (idx <= n) {
            fenwick[idx] ^= val;
            idx += idx & -idx;
        }
    }

    void rangeUpdate(int l, int r, int val) {
        updateBIT(l, val);
        if (r + 1 <= n) {
            updateBIT(r + 1, val);
        }
    }

    int pointQuery(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans ^= fenwick[idx];
            idx -= idx & -idx;
        }

        return ans;
    }

    void dfs(int u, int parent) {
        tin[u] = ++timer;
        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == parent) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        timer = 0;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n, 0);
        fenwick.assign(n + 2, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            bit[i] = getBit(s[i]);
        }

        // Root the tree at node 0.
        dfs(0, 0);

        // Initialize root-path XOR masks using subtree updates.
        for (int i = 0; i < n; i++) {
            rangeUpdate(tin[i], tout[i], bit[i]);
        }

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            stringstream ss(q);

            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int newBit = getBit(c);
                int delta = bit[u] ^ newBit;

                rangeUpdate(tin[u], tout[u], delta);

                bit[u] = newBit;
                s[u] = c;
            } 
            else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int mask = pointQuery(tin[u])
                         ^ pointQuery(tin[v])
                         ^ bit[w];

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
