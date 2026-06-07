class Solution {
public:
    bool consecutiveSetBits(int n) {
         int count = 0;

         while(n>0)
         {
            if((n&3)==3) //last 2 bits 
            {
                count++;
            }
            n>>=1;
         }
         return count==1;
    }
};