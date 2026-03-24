class Solution {
public:
    int beautySum(string s) {
        
        int n =s.size();
        int cnt = 0;
//substring using tradational 2 loop
        for(int i =0;i<n;i++)
        {
            vector<int>arr(26,0);

            for(int j= i;j<n;j++)
            {
                
                int maxe = INT_MIN;
                int mini = INT_MAX;

                arr[s[j]-'a']++;

                // vector bn gya 
                for(auto x: arr)
                {
                    if(x!=0)
                    {
                    maxe = max(maxe,x);
                    mini = min(mini,x); 
                    }
                }

                cnt += maxe-mini;
            }
    
        }

        return cnt;
    }
};