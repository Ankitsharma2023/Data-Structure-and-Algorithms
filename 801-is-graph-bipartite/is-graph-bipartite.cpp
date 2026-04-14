class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>color(n,-1); 

        queue<int>q;
        for(int i =0;i<n;i++)
        {
            if(color[i]==-1) //new node
            {
                q.push(i);
                color[i]= 0;//0 as a color
       
                while(!q.empty())
                {
                   int node = q.front();
                   
                   q.pop();

                   for(auto it : graph[node])
                   {
                     if(color[it] ==-1) //unvisited
                     {
                        color[it]= !color[node]; //0-->1 
                        q.push(it);
                     }
                     else if (color[it] == color[node]) return false;
                   }
                }

            }
        }

        return true;
    }
};