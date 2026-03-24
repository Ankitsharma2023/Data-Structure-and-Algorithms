class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {

        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);

        if (abs(diff) > total) return 0;
        if ((diff + total) % 2 != 0) return 0;

        int target = (diff + total) / 2;

        //  count zeros
        int zeros = count(arr.begin(), arr.end(), 0);

        //  remove zeros from array
        vector<int> nums;
        for (int x : arr) {
            if (x != 0) nums.push_back(x);
        }

        int m = nums.size();

        // 2D DP (smaller now because zeros removed)
        vector<vector<int>> t(m + 1, vector<int>(target + 1, 0));

        t[0][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= target; j++) {

                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        //  multiply zero effect
        return t[m][target] * pow(2, zeros);
    }
};