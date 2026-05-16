class Solution {
public:
    long long  hours(vector<int>& piles, int mid) {
        long long ans= 0;
        for(int i = 0 ;i <piles.size();i++)
        {
        if (piles[i] % mid == 0) { // fully divisible
            ans += piles[i] / mid;
        } else {
            ans += piles[i] / mid + 1;
        }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int ans = 0;
        if (piles.size() >h)
            return -1;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long  hourstoeat = hours(piles, mid);

            if (hourstoeat <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};