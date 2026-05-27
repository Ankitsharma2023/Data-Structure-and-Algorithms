class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> seen;
        int strength = 0;

        for(char ch : password) {

            if(seen.count(ch)) continue;

            seen.insert(ch);

            if(ch >= 'a' && ch <= 'z') {
                strength += 1;
            }
            else if(ch >= 'A' && ch <= 'Z') {
                strength += 2;
            }
            else if(ch >= '0' && ch <= '9') {
                strength += 3;
            }
            else {
                strength += 5;
            }
        }

        return strength;
    }
};