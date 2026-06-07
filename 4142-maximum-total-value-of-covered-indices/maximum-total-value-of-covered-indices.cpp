
class Solution {
public:
    using ll = long long;

    long long maxTotal(vector<int>& nums, string s) {
        int n = s.length();

        ll sum = 0;
        ll minm = 1e9;
        ll ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                sum += nums[i];
                minm = min(minm, 1LL * nums[i]);
            } else {
                if (minm != 1e9) {
                    sum += nums[i];
                    minm = min(minm, 1LL * nums[i]);

                    sum -= minm;
                    ans += sum;
                }

                minm = 1e9;
                sum = 0;
            }
        }

        if (sum != 0)
            ans += sum;

        return ans;
    }
};