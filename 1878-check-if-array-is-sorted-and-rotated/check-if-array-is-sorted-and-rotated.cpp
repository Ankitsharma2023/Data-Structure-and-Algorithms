class Solution {
public:
    bool check(vector<int>& nums) {
        
        int allowed = 0;
        if(nums.size()==1) return true;

        for(int i =0;i<nums.size();i++)
        {
           if(nums[i] > nums[(i+1) % nums.size()]) allowed++;       
         }

        return allowed <=1;
    }
};