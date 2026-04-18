class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

     

        int n = grid.size(); int m = grid[0].size();

            if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

            if (n == 1)
            return 1;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        queue<pair<int,pair<int,int>>>q;
//for better considering all scenario not this particular question
         pair<int, int> source = {0, 0};
        pair<int, int> dest = {n - 1, m - 1};

        q.push({1,{source.first,source.second}});
        dist[source.first][source.second] = 1;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty())
        {
            int step = q.front().first;
            int r = q.front().second.first;
            int c =q.front().second.second;
            q.pop();
            for(int i =0;i<8;i++)
            {
                int neigr = r +dr[i];
                int neigc = c+dc[i];

                if(neigr>=0 && neigr<n && neigc>=0 && neigc<m && grid[neigr][neigc]==0 && step+1<dist[neigr][neigc])
                {
                    dist[neigr][neigc] = 1 +step;

    //to stop at destination
    if(neigr==dest.first && neigc ==dest.second) return dist[neigr][neigc];
                    q.push({dist[neigr][neigc],{neigr,neigc}});
                }
            }
            
        }

        return -1; 
    }
};