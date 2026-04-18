class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       
 priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

            //diff,r,c

            int n = heights.size(); int m =heights[0].size();

            vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
            diff[0][0]=0;

            pq.push({0,{0,0}});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!pq.empty())
        {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r ==n-1 && c ==m-1) return effort;

            for(int i =0;i<4;i++)
            {
                int nr = r+dr[i]; int nc = c+dc[i];

                
                if (nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    int neweffort =max(abs(heights[nr][nc]-heights[r][c]), diff[r][c]);

                    if(neweffort <diff[nr][nc]) 
                    {
                        diff[nr][nc] = neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }

        return 0;

    }
};