class Solution {
public:
    bool isIsomorphic(string s, string t) {
    
        //imp check 
        if(s.size()!=t.size()) return false;

        unordered_map<char, char>st;
        
        unordered_map<char,char>ts;

        for(int i = 0;i<s.size();i++)
        {
            char a = s[i];
            char b = t[i];
// count define that this char exist already ,not a new one 
            if(st.count(a) && st[a]!=b) return false;
            if(ts.count(b) && ts[b]!=a) return false;
            st[a] =b;
            ts[b] = a;
        }

        return true;
        
    }
};