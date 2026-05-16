class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        // Build adjacency list
        for (auto &e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> indegree(numCourses, 0);
        
        // Calculate indegree
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        // Push nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // If all courses are processed, no cycle
        return cnt == numCourses;
    }
};
