class Solution {
public:

    void dfs(int node, vector<vector<int>>&isConnected,vector<int>&vis,int n)
    {
        vis[node]=1;
        for(int i =0;i<n;i++)
        {
            if(isConnected[node][i]==1 && !vis[i])
            {
                dfs(i,isConnected,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n);
        int cnt = 0;
        for (int i = 0; i <n; i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis,n);
                cnt++;
            }
        }
        return cnt;
    }
};