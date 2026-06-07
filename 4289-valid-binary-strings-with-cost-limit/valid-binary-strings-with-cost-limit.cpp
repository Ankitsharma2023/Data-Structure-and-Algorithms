class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        

        vector<string>ans;

        int total = 1<<n; // 2^3
        
        for(int num = 0 ; num<total ;num++) //loop every possible string 0 1  2 3 ......
        {
            string s = "";
            
            for(int i =n-1;i>=0;i--) // n= 3 -> i = 2,1,0
            {
                if(num & (1<<i)) // non zero bit is on , else off. hmm isme num ko = 101 , i =2,i=1,i= 0 //to i=2 ,0 on hoga ,left shift
                {
                    s+='1';
                }
                else
                {
                    s+='0';
                }
            }

             bool valid = true;
        int cost = 0;

        for(int i = 0;i<n;i++)
        {
            //calculate kro cost
            if(s[i]=='1') cost+=i;

            if(i>0 && s[i]=='1' && s[i-1]=='1') valid = false;
        }

        if(valid && cost<=k) ans.push_back(s);

        }

        return ans;

       
    }
};
