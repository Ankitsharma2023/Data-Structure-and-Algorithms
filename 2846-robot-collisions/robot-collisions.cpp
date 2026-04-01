class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        
        vector<pair<int,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        
        sort(robots.begin(), robots.end());
        
        stack<int> st; 
        
        // Step 3: process collisions
        for(auto &p : robots) {
            int i = p.second;
            
            if(directions[i] == 'R') {
                st.push(i);
            } 
            else {
                // direction 'L'
                while(!st.empty() && healths[i] > 0) {
                    int j = st.top(); // last 'R' robot
                    
                    if(healths[j] < healths[i]) {
                        st.pop();
                        healths[i]--;
                        healths[j] = 0;
                    }
                    else if(healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        break;
                    }
                    else {
                        st.pop();
                        healths[j] = 0;
                        healths[i] = 0;
                        break;
                    }
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};