#include <numeric>
#include <vector>
#include <cmath>


using namespace std;
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int subtotal{0}, count{0};
        int total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size() - 1; ++i){
            subtotal += nums[i];
            total -= nums[i];
            if (abs(subtotal - total) % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
};