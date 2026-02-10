class Solution {
public:

 int calculate(int mid , vector<int>&arr, int n )
 {
    int ans = 1;
    int sum=0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]+sum>mid)
        {
            ans++;
            sum = 0;
        }
        sum+=arr[i];
    }
    return ans;
 }
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        int ans = 0;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            int res = calculate(mid , nums, n);

            if(res<=k)
            {
                ans = mid;
                 high = mid - 1;
            }
            else
            {
                 low = mid+1;
            }
        }
        return ans;
    }
};