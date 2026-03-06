class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int ans = 0 ;

//normal using 2 loop for calculating all substring 

        for(int i =0 ; i<n; i++)
        {
            //count array, for each iteration it reset
            int count[26] = {0};

            for(int j = i ; j < n ; j++)
            {
                int mn = INT_MAX;
                int mx = INT_MIN;
                count[s[j] - 'a']++;
            

            for(auto x : count)
            {
                if(x!=0)
                {
                    mn = min(x,mn);
                    mx = max(x,mx);
                }
            }

            ans += mx-mn;
            }
        }
        return ans;
    }
};