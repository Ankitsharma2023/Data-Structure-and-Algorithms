class Solution {
public:

 bool isPalindrome(string& X, int i, int j) {  
        while (i <= j) {
            if (X[i] != X[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

int solve(string&str,int i ,int j , vector<int>&t)
{
    if(i>=j) return 0;
    if(t[i]!=-1) return t[i];

    int ans=INT_MAX;

    for(int k =i;k<=j-1;k++)
    {
        if(isPalindrome(str,i,k))
        {
            int temp_ans = 1+solve(str,k+1,j,t);
            ans = min(ans,temp_ans);
        }
    }
    return t[i]=ans;
}
    int minCut(string s) {
        
        int n = s.length();
        vector<int>t(n,-1);
        return solve(s,0,n,t)-1;
    }
};