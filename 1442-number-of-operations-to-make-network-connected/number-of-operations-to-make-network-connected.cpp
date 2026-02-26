class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int n) {
        vis[i] = 1;

        for (auto x : adj[i]) {
            if (!vis[x]) {
                dfs(x, adj, vis, n);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        // not enough cable
        if (connections.size() < n - 1)
            return -1;

        // simple ans only approach --> no of provinces

        vector<vector<int>> adj(n);
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis, n);
            }
        }
        return cnt - 1;
    }
};