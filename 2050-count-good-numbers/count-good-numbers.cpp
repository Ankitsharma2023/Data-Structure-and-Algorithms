class Solution {
public:
    long long MOD = 1e9 + 7;

    long long powerMod(long long x, long long n) {
        long long result = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % MOD;
                n--;
            } else {
                x = (x * x) % MOD;
                n /= 2;
            }
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long ans = (powerMod(5, evenCount) * powerMod(4, oddCount)) % MOD;

        return (int)ans;
    }
};