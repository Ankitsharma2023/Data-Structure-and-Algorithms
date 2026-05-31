class Solution {
public:
    int digitFrequencyScore(int n) {
        //basically sum of numbers
        int score = 0;
        
        while (n > 0) {
            score += n % 10;
            n /= 10;
        }
        
        return score;
    }
};