class Solution {
public:
    string largestOddNumber(string num) {

        int i =num.size()-1;

        while(i>=0 && (num[i]-'0')%2==0) //even
        {
            i--;
        }
        // after this we pointed at odd position
        //  if(i < 0) return "";

       return num.substr(0,i+1); // i+1 not included
    }
};