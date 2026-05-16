class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;

        int drow[4] = {-1,0,1,0} ;
        int dcol[4] = {0,1,0,-1};

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    vis[i][j] =1;

                       queue<pair<int,int>>q;
                       q.push({i,j});

                       while(!q.empty())
                       {
                    auto[row,col] = q.front();
                    q.pop();

                    for(int k=0;k<4;k++)
                    {
                        int nrow = row+drow[k];
                        int ncol = col +dcol[k];
                       
                       if(nrow>=0 && nrow < n && ncol >=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                       {
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                       }


                    }
                       }
                }
            }
        }


        return cnt;
    }
};