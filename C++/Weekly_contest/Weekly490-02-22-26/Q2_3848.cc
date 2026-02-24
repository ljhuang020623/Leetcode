#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> freq;
        int original = n;
        int result = 0;
        while(n > 0){
            int digits = n % 10;
            freq[digits]++;
            int k = factorial(digits);
            result += k;
            n /= 10;
        }
        if (checkPermutation(result, freq)) return true;
        else return original == result;
    }

private:
    int factorial(int n){
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }
    bool checkPermutation(int n, unordered_map<int, int> freq){
        while(n > 0){
            int digits = n % 10;
            freq[digits]--;
            n /= 10;
        }
        for (auto& [key, value] : freq){
            if (value != 0){
                return false;
            }
        }
        return true;
    }
};