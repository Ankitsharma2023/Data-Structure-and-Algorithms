class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        
        long long sum = 0;
 //it mean n-k <= x <= n+k
        for(int x = max(1,n-k); x<=n+k;x++)
        {
            if((n&x)==0) sum+=x;
        }
        return sum;
    }
};