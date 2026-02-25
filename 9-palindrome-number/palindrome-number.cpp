class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int p =x;
        long long y= 0;
         while(x>0)
         {
            long long ld = x%10;
             y = (y*10)+ld;
            x=x/10;
         }
         return y == p;
    }
};