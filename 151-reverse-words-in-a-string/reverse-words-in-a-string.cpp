class Solution {
public:

    string reverseWords(string s) {
        
        stringstream ss(s); // ss is not keyword 
        string word;
        vector<string> arr;


        while (ss >> word) { // similar to cin>>word
            arr.push_back(word);
        }

        // reverse words
        reverse(arr.begin(), arr.end());

        // build result
        string result = "";
        for (int i = 0; i < arr.size(); i++) {
            result += arr[i];
            if (i != arr.size() - 1) result += " "; //we dont want last word to have a trailing/leading zero
        }

        return result;
    }
};