class Solution {
public:
    int majorityElement(vector<int>& nums) {
     unordered_map<int,int>mpp;
     int n = nums.size();
     for(auto num:nums)
     {
        mpp[num]++;
     }   
     for(auto x:mpp)
     {
        if(x.second>n/2) return x.first;
     }
     return 0;
    }
};