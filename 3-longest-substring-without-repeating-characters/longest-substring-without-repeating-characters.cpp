class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l =0;
        unordered_map<char,int>mpp;
        int ans = 0;
        for(int r = 0 ;r < s.size();r++)
        {
            while(mpp.find(s[r])!=mpp.end()) //found 
            {
                mpp.erase(s[l]);l++;
            }
            mpp[s[r]]++;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};