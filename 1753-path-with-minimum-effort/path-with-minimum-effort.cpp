class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));

        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n-1 && col == m-1)
                return effort;

            if (effort > diff[row][col]) continue;

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    int neweffort = max(
                        abs(heights[row][col] - heights[newr][newc]),
                        diff[row][col]
                    );

                    if (neweffort < diff[newr][newc]) {
                        diff[newr][newc] = neweffort;
                        pq.push({neweffort, {newr, newc}});
                    }
                }
            }
        }

        return 0;
    }
};
