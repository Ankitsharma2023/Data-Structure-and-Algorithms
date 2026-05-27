class Solution {
public:

    // Function to calculate minimum operations
    // needed to convert remainder 'a' into remainder 'b'
    int dist(int a, int b, int k) {

        // Operations if we keep incrementing
        int inc = (b - a + k) % k;

        // Operations if we keep decrementing
        int dec = (a - b + k) % k;

        // Take minimum of both directions
        return min(inc, dec);
    }

    int minOperations(vector<int>& nums, int k) {

        int ans = INT_MAX;

        // Try every possible remainder for:
        // x -> even indices
        // y -> odd indices

        for (int x = 0; x < k; x++) {

            for (int y = 0; y < k; y++) {

                // x and y must be different
                if (x == y) continue;

                int ops = 0;

                // Traverse the array
                for (int i = 0; i < nums.size(); i++) {

                    // Current remainder of element
                    int rem = nums[i] % k;

                    // Even index
                    if (i % 2 == 0) {

                        // Convert current remainder -> x
                        ops += dist(rem, x, k);
                    }

                    // Odd index
                    else {

                        // Convert current remainder -> y
                        ops += dist(rem, y, k);
                    }
                }

                // Take minimum operations among all pairs
                ans = min(ans, ops);
            }
        }

        return ans;
    }
};