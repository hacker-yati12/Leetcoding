class Solution {
public:
    const static int MOD = 1e9 + 7;

    long long mod_pow(long long base, long long exp, int mod = MOD) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp & 1) { 
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1; 
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        if(n==1)
            return 5;
        if(n&1) {
            return (mod_pow(5, (n-1)/2) * mod_pow(4, n/2) + 4)%MOD;
        } else
            return (mod_pow(5, n/2) * mod_pow(4, n/2))%MOD;
    }
};