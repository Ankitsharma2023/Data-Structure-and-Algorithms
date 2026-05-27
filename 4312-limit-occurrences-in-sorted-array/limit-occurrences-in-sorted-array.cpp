class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
     
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        vector<int>res;

        for(auto c: mpp){
        int val = c.first;
        int freq = c.second;
            if(freq>k){
            for(int j=0;j<k;j++){
                res.push_back(val);
            }
        }else{
                for(int j=0;j<freq;j++){
                    res.push_back(val);
                }
        }
        }
        sort(res.begin(),res.end());
    return res;
    }
};