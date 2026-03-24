class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<long long>> t(n+1, vector<long long>(amount+1));

        for(int i = 0; i <= n; i++)
            t[i][0] = 1;

        for(int j = 1; j <= amount; j++)
            t[0][j] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(coins[i-1] <= j)
                {
                   t[i][j] = min( (long long)1e18, t[i][j - coins[i-1]] + t[i-1][j] ); 
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return (int)t[n][amount]; 
    }
};