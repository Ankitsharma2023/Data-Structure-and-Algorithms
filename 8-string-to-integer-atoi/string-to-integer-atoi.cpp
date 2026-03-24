class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
         
        // ignore whitespace 
        while(i<n && isspace(s[i])) i++;

        // check sign 
        int sign =1;
        if(i<n && s[i]=='-') 
        {sign = -1; i++;}
        else if(i<n && s[i]=='+') 
        {sign = 1;i++;}

        // check number
        long long result = 0;
        while(i<n && isdigit(s[i]))
        {
            result = result*10 +(s[i]-'0');
              if(sign == 1 && result>INT_MAX ) return INT_MAX;
        else if(sign ==-1 &&result>INT_MAX ) return INT_MIN;
            i++;
        }

        //rounding
    

        return sign*result;

    }
};