class Solution {
public:

    double angle(double x, double y, double z) {
        double val = (y*y + z*z - x*x) / (2*y*z);
        
        // avoid floating error
        // val = max(-1.0, min(1.0, val));
        
        return acos(val) * 180.0 / M_PI;
    }

    vector<double> internalAngles(vector<int>& sides) {
        
        
        sort(sides.begin(), sides.end());
        int a = sides[0], b = sides[1], c = sides[2];

        if (a + b <= c) return {};

        double A = angle(a, b, c);
        double B = angle(b, a, c);
        double C = angle(c, a, b);

        vector<double> angles = {A, B, C};
        sort(angles.begin(), angles.end());

        return angles;
    }
};