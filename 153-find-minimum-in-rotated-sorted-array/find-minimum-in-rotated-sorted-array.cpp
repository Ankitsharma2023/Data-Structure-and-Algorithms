class Solution {
public:
    int findMin(vector<int>& nums) {
        

        int n =nums.size();

        int low = 0;
        int high = nums.size()-1;
        
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high - low) / 2;

            //left half sorted
            if(nums[low]<=nums[mid])
            {

                if(nums[low]<ans)
                {
                    ans = nums[low];
                }
                low = mid+1;
            }
            else
            {
                // right half is sorted : nums[mid]<=nums[high]
                
                if(nums[mid]<ans)
                {
                    ans = nums[mid];
                }
                high = mid-1;
            }

        }
        return ans;
    }
};