class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
           int result = INT_MAX;

         
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}}); // distance,node,k

        while (!pq.empty()) {
            int cost = pq.front().first;
            int node = pq.front().second.first;
            int step = pq.front().second.second;
            pq.pop();
            
         if (step > k + 1)
                continue;

            if (node == dst) {
                result = min(result, cost);
                continue;
            }

            for(auto it : adj[node])
            {
               int next = it.first;
               int wt =it.second;

                if( cost + wt < dist[next] )
                {
                    dist[next] = cost + wt;
                    pq.push({dist[next],{next,step+1}});
                }
            }
        }

           return result == INT_MAX ? -1 : result; 
    }
};