class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // make input in adjacency list
        // i will use bfs traversal,i will add cost, k , post in queue
        // then when i got pos == dst , then the associated cost i will store as
        // answer and keep moving , and my limit is k should be upto
        // k+1(including dest)
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        int result = INT_MAX;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            int cost = curr.first;
            int stops = curr.second.first;
            int node = curr.second.second;
            q.pop();
            if (stops > k + 1)
                continue;

            if (node == dst) {
                result = min(result, cost);
                continue;
            }

            for (auto it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                int newcost = cost + wt;

                if (newcost < dist[next]) {
                    dist[next] = newcost;
                    q.push({newcost, {stops + 1, next}});
                }
            }
        }

        return result == INT_MAX ? -1 : result;    }
};