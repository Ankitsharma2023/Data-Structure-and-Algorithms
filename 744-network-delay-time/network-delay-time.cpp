class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

       vector<vector<pair<int,int>>>adj(n+1);

       for(auto &e: times)
       {
        int u =e[0];int v =e[1];int w=e[2];
        adj[u].push_back({v,w}); 
       }
       
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;      
    vector<int> dist(n +1, INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
      
        while (!pq.empty()) {

            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                int v = it.first;
                int wt =it.second;

                if(distance + wt <dist[v])
                {
                    dist[v] = wt+distance;
                    pq.push({dist[v],v});
                }
            }

        }

          int ans = INT_MIN;
          // find min in dist array
            for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};