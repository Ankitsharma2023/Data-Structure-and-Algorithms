class Solution {
public:

    void solve(int idx,int n,int k,int cost,char prev,string &curr,vector<string>&ans){

        if(cost>k) return;
        
        if(idx==n){
            ans.push_back(curr);
            return;
        }

        //take 0
        curr.push_back('0');
        solve(idx+1,n,k,cost,'0',curr,ans);
        curr.pop_back();

        //take 1
        if(prev!='1' && cost+idx<=k){
            curr.push_back('1');
            solve(idx+1,n,k,cost+idx,'1',curr,ans);
            curr.pop_back();
        }

        
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string curr="";
        solve(0,n,k,0,'0',curr,ans);
        return ans;
    }
};