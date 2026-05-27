class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;//single 
         int res = INT_MAX;
        int idx = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                idx = i;
                break;
            }
        }
        int flag1 = 1;
        int flag2 = 1;
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n] != (nums[i]+1)%n){
                flag1 =0;
                
            }
            if(nums[(i+1)%n] != (nums[i]-1+n)%n){
                flag2 = 0;
            }
        }
       
        if(!flag1 && !flag2){
            return -1;
        }
    if(flag1){
        if(idx ==0){
            res = min(res,0);
        }else{
            res = min(res, min(idx,n-idx+2));
        }
    }
        if(flag2){
            res = min(res, min((idx+1)%n+1,n-idx));
        }
    return res;
    }
};