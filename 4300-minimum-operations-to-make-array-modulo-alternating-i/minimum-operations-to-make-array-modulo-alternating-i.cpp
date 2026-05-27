class Solution {
public:

    int dist(int a, int b, int k) {

        // incre
        int inc = (b - a + k) % k;

        // decrem
        int dec = (a - b + k) % k;

        //  minimum 
        return min(inc, dec);
    }

    int minOperations(vector<int>& nums, int k) {

        int ans = INT_MAX;



        for (int x = 0; x < k; x++) {

            for (int y = 0; y < k; y++) {

               //same ko skip kro
                if (x == y) continue;

                int ops = 0;

                for (int i = 0; i < nums.size(); i++) {

                    int rem = nums[i] % k;

                    // Even index
                    if (i % 2 == 0) {

                        ops += dist(rem, x, k);
                    }

                    // Odd index
                    else {

                
                        ops += dist(rem, y, k);
                    }
                }

        
                ans = min(ans, ops);
            }
        }

        return ans;
    }
};