#include <algorithm>
using namespace std;



class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long ans = 0;
        long long commas = 1;
        while (start <= n){
            long long end = start * 1000 - 1;
            long long right = min(end, n);
            ans += (right - start + 1) * commas;
            start *= 1000;
            commas++;
        }
        return ans;

    }
};