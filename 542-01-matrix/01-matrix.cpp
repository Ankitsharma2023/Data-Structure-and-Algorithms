class Solution {
public:

     void bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>&dis, vector<vector<char>>&vis, vector<vector<int>>&mat)
     {
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            
            dis[r][c] = step;
            q.pop();

            for(int i =0;i<4;i++)
            {
                for(int j = 0; j<4;j++)
                {
                    int neighr = r+drow[i];
                    int neighc = c+dcol[i];

                    if(neighr>=0 && neighr<mat.size() && neighc >=0 && neighc <mat[0].size() && !vis[neighr][neighc])
                    {
                        vis[neighr][neighc] =true;
                        q.push({{neighr,neighc},step+1});
                    }
                }
            }
        }
     }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dis(n,vector<int>(m));
        vector<vector<char>>vis(n,vector<char>(m,false));

        queue<pair<pair<int,int>,int>>q;

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=true;
                    q.push({{i,j},0}); //0 is for step
                }
            }
        }

        bfs(q,dis,vis,mat);

        return dis;

    }
};