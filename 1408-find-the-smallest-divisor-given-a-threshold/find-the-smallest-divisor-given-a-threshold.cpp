class Solution {
public:
    long long calcualtethreshold(int mid ,vector<int>&arr)
    {
        int n = arr.size();
         long long sum = 0;
        for(int i = 0;i<n;i++)
        {
  sum += (arr[i] + mid - 1) / mid;          }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
int high = *max_element(nums.begin(), nums.end());

        int ans = 0;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            long long res = calcualtethreshold(mid , nums);

            if(res<=threshold)
            {
                ans = mid;
             high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};