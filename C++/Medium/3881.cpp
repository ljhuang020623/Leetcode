#include <algorithm>
using namespace std;



class Solution {
public:
    const int mod = 1e9 + 7;

    // Compute a ^ e % mod 
    // a ^ -1 has the same remainder as a ^ (mod - 2), (% mod)
    // binary exponentiation
    long long modPow(long long a, long long e){
        long long res = 1;
        while (e > 0){
            if (e & 1) res = res * a % mod;
            a = a * a % mod;
            e >>= 1;
        }
        return res;
    }


    // C(n, k) = {n(n - 1)(n - 2) ... * (n - k + 1)} / {1 * 2 * 3 * ...k} 
    long long comb (int n, int k){
        if (k < 0 || k > n) return 0;

        k = min(k, n - k);
        long long numerator = 1;
        long long denominator = 1;
        for (int i = 1; i <= k; i++){
            numerator = numerator * (n - i + 1) % mod;
            denominator = denominator * i % mod;
        }
        // C(n, k) = numerator * (denominator ^ -1) (% mod)
        return numerator * modPow(denominator, mod - 2) % mod;

    }

    int countVisiblePeople(int n, int pos, int k) {
        // choose k ppl from n - 1 position (n total ppl minus pos)'
        // pos can either be L or R it wont affect the amount of k
        //
        // 2 * C(n - 1, k) % mod 
        // C(n - 1, k) = fact[n - 1] * invFact[k] % mod * invFact[n - 1 -k] % mod
        // C(n - 1, k) gets super large if u dont mod it during the calculation
        // 
        // We need 3 things:
        // 1. modPow(a, e): compute a ^ e % mod
        // 2. fact[i] = i! % mod
        // 3. invFact[i] = inverse of i! % mod
        // fermat little theorem
        

        return (int)(2LL * comb(n - 1, k) % mod);
    }
    
    
};  