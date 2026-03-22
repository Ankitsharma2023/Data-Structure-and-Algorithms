class Solution {
public:

    bool subsetsum(vector<int>&nums,int target)
    {
        int n =nums.size();
        vector<vector<bool>>t(n+1,vector<bool>(target+1)); //t[n+1][target+1]

        for(int i =0;i<n+1;i++) t[i][0] = true;
        for(int j=1;j<target+1;j++) t[0][j] = false;

        for(int i =1;i<n+1;i++)
        {
            for(int j =1;j<target+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        
        
        int sum=0;
        for(int x:nums) sum+=x;

// if sum is odd of array , cant possible to find. 
        //odd
        bool ans =false;
        if(sum%2==1) return false;
        else //even
        {
            //divide sum in 2 partition
             int target = sum/2;

              ans = subsetsum(nums,target);
        }

        return ans;
    }
};