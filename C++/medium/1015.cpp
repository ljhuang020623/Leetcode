class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int length{0};
        int rem{0};
        if (k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        while(true){
            rem = (rem * 10 + 1) % k;
            length += 1;
            if(rem % k == 0){
                return length;
            }
        }
    }
};