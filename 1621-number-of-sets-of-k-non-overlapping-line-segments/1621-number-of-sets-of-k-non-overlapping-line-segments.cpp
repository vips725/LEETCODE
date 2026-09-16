class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    
    long long modInverse(long long a) {
        return modPow(a, MOD - 2);
    }
    
    int numberOfSets(int n, int k) {
 
        vector<long long> fact(n + k + 1, 1), invFact(n + k + 1, 1);
        for (int i = 1; i <= n + k; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[n + k] = modInverse(fact[n + k]);
        for (int i = n + k - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        
        auto nCr = [&](int a, int b) {
            if (b < 0 || b > a) return 0LL;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };
        
        return (int)nCr(n + k - 1, 2 * k);
    }
};
