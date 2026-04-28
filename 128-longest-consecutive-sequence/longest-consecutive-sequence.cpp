class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int ans = 1;

        if (n == 0)
            return 0;
        unordered_set<int> st;

        for (int x : nums)
            st.insert(x);

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) // element not present
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) // element present
                {
                    x = x + 1;
                    cnt++;
                }
                  ans = max(ans, cnt);
            }

          
        }
        return ans;
    }
};