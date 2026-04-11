#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (auto& x : nums){
            while (x > 0){
                if (x % 10 == digit){
                    ans += 1;
                }
                x /= 10;
            }
        }    
        return ans;
    }
    
};