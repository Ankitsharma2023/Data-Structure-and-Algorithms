class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();

        const long long NEG = -1e18;

        vector<long long> dp(2, NEG), ndp(2, NEG);

        int x0 = (s[0] == '1') ? 1 : 0;   // token at 0 cannot move
        dp[x0] = 0;

        for (int i = 0; i < n - 1; i++) {
            fill(ndp.begin(), ndp.end(), NEG);

            for (int xi = 0; xi <= 1; xi++) {
                if (dp[xi] == NEG) continue;

                vector<int> choices;
                if (s[i + 1] == '1')
                    choices = {0, 1};
                else
                    choices = {0};

                for (int xnext : choices) {
                    bool covered =
                        ((s[i] == '1') && xi == 1) ||
                        ((s[i + 1] == '1') && xnext == 0);

                    long long gain = covered ? nums[i] : 0;

                    ndp[xnext] =
                        max(ndp[xnext], dp[xi] + gain);
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (int lastState = 0; lastState <= 1; lastState++) {
            if (dp[lastState] == NEG) continue;

            long long cur = dp[lastState];

            if (s[n - 1] == '1' && lastState == 1)
                cur += nums[n - 1];

            ans = max(ans, cur);
        }

        return ans;
    }
};