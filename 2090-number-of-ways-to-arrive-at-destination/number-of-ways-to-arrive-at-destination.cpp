class Solution {
public:
    // T.C = ElogV  --> same as dijsktra algo
    typedef pair<long, long> p;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathcnt(n, 0);

        result[0] = 0;
        pathcnt[0] = 1; // self

        pq.push({0, 0}); // time , node

        while (!pq.empty()) {
            long long currtime = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            // JUST AN OPTIMISATION 
             if (currtime > result[node]) continue; 

            for (auto it : adj[node]) {
                int next = it.first;
                int time = it.second;

                if (currtime + time < result[next]) {
                    result[next] = currtime + time;
                    pq.push({result[next], next});

                    pathcnt[next] =
                        pathcnt[node]; // same path count as the path count of
                                       // your parent if first time less than
                                       // value encounter
                } else if (currtime + time == result[next]) {
                    pathcnt[next] = (pathcnt[node] + pathcnt[next]) % M;
                }
            }
        }
        return pathcnt[n - 1];
    }
};