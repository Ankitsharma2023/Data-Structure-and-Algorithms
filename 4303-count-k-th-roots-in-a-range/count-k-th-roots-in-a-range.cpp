class Solution {
public:

    int countKthRoots(int l, int r, int k) {
        return count(r, k) - count(l - 1, k);
    }

    int count(int n, int k) {

        if (n < 0) return 0;

        int low = 0;
        int high = n;
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (power(mid, k, n)) {
                ans = mid;
                low = mid + 1;  // check aage 
            }
            else {
                high = mid - 1;
            }
        }

        return ans + 1; // include 0
    }

    // checks if base^k <= limit
    bool power(long long base, int k, int limit) {

        long long result = 1;

        for (int i = 0; i < k; i++) {

            result *= base;

            if (result > limit) {
                return false;
            }
        }

        return true;
    }
};