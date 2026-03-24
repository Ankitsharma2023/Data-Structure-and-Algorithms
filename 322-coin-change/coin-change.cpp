class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> t(n+1, vector<int>(amount+1));

        // base case
        for(int i = 0; i <= n; i++)
            t[i][0] = 0;

        for(int j = 1; j <= amount; j++)
            t[0][j] = 1e9;   // impossible (infinity)

        // fill dp
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(coins[i-1] <= j)
                {
                  // 1 is the current coin you picked
                    t[i][j] = min(
                        1 + t[i][j - coins[i-1]],   // take coin
                        t[i-1][j]                   // skip coin
                    );
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        // if not possible
        if(t[n][amount] >= 1e9) return -1;

        return t[n][amount];
    }
};