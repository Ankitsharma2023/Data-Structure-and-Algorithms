class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        long long ans = 0;
        long long per_point = ceil((double)brightness / 3);

        long long left = intervals[0][0];
        long long right = intervals[0][1];

        for(int i =1;i<intervals.size();i++)
        {
            long long currleft = intervals[i][0];
            long long currright = intervals[i][1];

            if(currleft<=right) right = max(right,currright);
            else
            {
                ans +=(right-left+1);
                left =currleft;
                right = currright;
            }
        }

        ans+=(right-left+1);
        ans*=per_point;

        return ans;
    }
};