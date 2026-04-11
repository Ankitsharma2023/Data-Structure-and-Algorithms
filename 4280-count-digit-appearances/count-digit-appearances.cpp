class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
       int cnt =0;
       for(auto &e : nums)
       {
        //12-->54-->32-->22
         string s = to_string(e);
         for(char c: s)
         {
            if(c-'0'==digit) cnt++;
         }
       }
       return cnt;
    }
}; 