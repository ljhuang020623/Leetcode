class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = 0;
        int temp = n;
        // make a mask the exact length of n
        // mask means all 1s
        while (temp > 0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        return n ^ mask;
    }

};