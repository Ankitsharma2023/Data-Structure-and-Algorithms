

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;

        for (const string& event : events) {

            if (counter >= 10) {
                break;
            }

            if (event == "W") {
                counter++;
            } else if (event == "WD") {
                score += 1;
            } else if (event == "NB") {
                score += 1;
            } else if (event == "0") {
                score += 0;
            } else if (event == "1") {
                score += 1;
            } else if (event == "2") {
                score += 2;
            } else if (event == "3") {
                score += 3;
            } else if (event == "4") {
                score += 4;
            } else if (event == "6") {
                score += 6;
            }
        }

        return {score, counter};
    }
};