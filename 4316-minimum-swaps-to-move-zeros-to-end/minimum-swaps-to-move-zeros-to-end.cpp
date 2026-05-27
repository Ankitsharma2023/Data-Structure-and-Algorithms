class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

     int n = nums.size();
     int zeroes = 0;
     for(int x: nums)    if(x==0) zeroes++;
     int cnt = 0;
     for(int i = 0;i <n-zeroes;i++)
     {
        if(nums[i]==0) cnt++;
     }

     return cnt;
    }
};