class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();//row
        int m = grid[0].size(); // col
        
        vector<vector<int>> res(n, vector<int>(m,1));
        
        int mod = 12345;
        
        // prefix in 2d 
        
        long long prefix  =1 ;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res[i][j] = prefix;
                prefix = (prefix*grid[i][j])%mod;
            }
        }
        
        
        // we get prefix 2d array 
        
        long long suffix = 1;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                res[i][j] = (1LL*res[i][j] *suffix)%mod;
                suffix =  (suffix*grid[i][j])%mod;
            }
        }
        
        return res;
    }
};