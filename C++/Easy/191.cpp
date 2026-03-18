class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n > 0){
            int setBit = (n & 1);
            result += setBit;
            n >>= 1;
        }
        return result;
    }
};