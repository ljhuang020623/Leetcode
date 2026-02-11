#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < (int)nums.size(); i++){
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};