class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, 1e9));
        
        queue<pair<pair<int,int>, int>> q; // ((r,c), time)
        
        
        for(auto &it : sources) {
            int r = it[0];
            int c = it[1];
            int color = it[2];
            
            grid[r][c] = color;
            time[r][c] = 0;
            q.push({{r,c}, 0});
        }
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        
        while(!q.empty()) {
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    
                    // first time or shorter time
                    if(time[nrow][ncol] > t + 1) {
                        time[nrow][ncol] = t + 1;
                        grid[nrow][ncol] = grid[r][c];
                        q.push({{nrow,ncol}, t+1});
                    }
                    // same time → conflict
                    else if(time[nrow][ncol] == t + 1) {
                        grid[nrow][ncol] = max(grid[nrow][ncol], grid[r][c]);
                    }
                }
            }
        }
        
        return grid;
    }
};