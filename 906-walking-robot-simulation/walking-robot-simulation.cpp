class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Store obstacles in set for fast lookup
        set<pair<int,int>> obs;
        for (auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }

        // Directions: North, East, South, West
        vector<pair<int,int>> dir = {
            {0,1},   // North
            {1,0},   // East
            {0,-1},  // South
            {-1,0}   // West
        };

        int d = 0; // current direction index (start = North)
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {

            // Turn right
            if (cmd == -1) {
                d = (d + 1) % 4;
            }
            // Turn left
            else if (cmd == -2) {
                d = (d + 3) % 4; // same as (d - 1 + 4) % 4
            }
            // Move forward
            else {
                for (int step = 0; step < cmd; step++) {

                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    // If next position is obstacle → stop moving
                    if (obs.count({nx, ny})) break;

                    // Otherwise move
                    x = nx;
                    y = ny;

                    // Update max distance squared
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};