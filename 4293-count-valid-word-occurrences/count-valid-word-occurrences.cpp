class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
          // Step 1: make one complete string
        string s = "";

        for (string &x : chunks) {
            s += x;
        }

        unordered_map<string, int> mp;

        string cur = "";

        int n = s.size();

        // Step 2: traverse string
        for (int i = 0; i < n; i++) {

            char ch = s[i];

            // CASE 1: normal letter
            if (ch >= 'a' && ch <= 'z') {
                cur += ch;
            }

            // CASE 2: hyphen
            else if (ch == '-') {

                // hyphen valid only if surrounded by letters
                if (i > 0 && i < n - 1 &&
                    s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                    s[i + 1] >= 'a' && s[i + 1] <= 'z') {

                    cur += '-';
                }
                else {
                    // invalid separator
                    if (!cur.empty()) {
                        mp[cur]++;
                        cur = "";
                    }
                }
            }

            // CASE 3: separator like space
            else {
                if (!cur.empty()) {
                    mp[cur]++;
                    cur = "";
                }
            }
        }

        // last word remaining
        if (!cur.empty()) {
            mp[cur]++;
        }

        // Step 3: answer queries
        vector<int> ans;

        for (string &q : queries) {
            ans.push_back(mp[q]);
        }

        return ans;
    }
};