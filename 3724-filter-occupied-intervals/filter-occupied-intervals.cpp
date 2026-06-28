class Solution {
public:
    // question to me :Merge all busy intervals first, then erase the free
    // interval from them, and return the remaining busy intervals.
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {

        // merge interval
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        // Merge overlapping aur  touching intervals
        for (auto& it : occupiedIntervals) {

            if (merged.empty()) {
                merged.push_back(it);
                continue;
            }

            auto& last = merged.back();

            if (it[0] <= last[1] + 1) {
                last[1] = max(last[1], it[1]);
            } else {
                merged.push_back(it);
            }
        }
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
        // < -- -- -- -- -- --->< -- -- ---><-- -- -- -->**********

        vector<vector<int>> ans;

        // Remove the free interval
        for (auto& it : merged) {
            long long l = it[0], r = it[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({(int)l, (int)r});
                continue;
            }

            // Left part
            if (l < freeStart) {
                ans.push_back({(int)l, freeStart - 1});
            }

            // Right part
            if (r > freeEnd) {
                ans.push_back({freeEnd + 1, (int)r});
            }
        }

        return ans;
    }
};