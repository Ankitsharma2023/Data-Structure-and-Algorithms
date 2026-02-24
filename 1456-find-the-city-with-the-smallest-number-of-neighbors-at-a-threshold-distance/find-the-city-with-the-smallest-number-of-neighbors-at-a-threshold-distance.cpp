class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // making of matrix from edges 
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
        for(auto it : edges)
        {
           matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
        for(int i =0;i<n;i++) matrix[i][i] =0;

        for(int k =0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {

                    if(matrix[i][k]==INT_MAX  || matrix[k][j] ==INT_MAX) continue;
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k]+ matrix[k][j]);
                }
            }
        }

       // now the main algorithm 
       int cityno = -1; 
       int cntcity = INT_MAX;
       for(int i =0;i<n;i++) // main city , rows
       {
        int cnt = 0;
        for(int j =0;j<n;j++) 
        {//adjacent city,col
        if(matrix[i][j]<=distanceThreshold) cnt++;
        }
        if(cnt <= cntcity) 
        {
            cntcity = cnt;
            cityno = i;
        } 
       }

       return cityno;
    }
};