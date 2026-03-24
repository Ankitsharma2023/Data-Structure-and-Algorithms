class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = INT_MIN;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(') cnt++;
              ans = max(ans,cnt);
            if(s[i]==')') cnt--;
            
        }
        return ans;
    }
};