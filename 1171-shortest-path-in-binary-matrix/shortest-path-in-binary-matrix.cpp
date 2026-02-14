class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
          if (n == 1)
            return 1;

 
        // source as 0,0 and destination as n-1,n-1;
        pair<int, int> source = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        // delta row and col
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            // row and col
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]) {
                    dist[nr][nc] = 1 + dis;
                    if (nr == dest.first && nc == dest.second)
                        return dist[nr][nc];
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return -1;
    }
};