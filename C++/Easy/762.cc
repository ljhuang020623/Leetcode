class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++){
            int count = countSetBits(i);
            if (isPrime(count)) result++; 
        }
        return result;
    }

private:
    // Brian Kernighan's algorithm
    // 1. Identifying the rightnost set bit using the expression n & (n - 1), this
    //    clears the least significant set bit of n
    // 2. Repeat this until n becomes 0
    // 3. count the number of iterations
    int countSetBits(int n){
        int count = 0;
        while(n > 0){
            n &= (n - 1);
            count ++;
        }
        return count;
    }
    bool isPrime(int n){
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++){
            if (n % i == 0) return false;
        }
        return true;
    }
};