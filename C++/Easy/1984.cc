#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n{static_cast<int>(nums.size())};
        int min_diff{nums[n - 1] - nums[0]};

        for (int i = 0; i < n - k + 1; i++){
            if (nums[i + k - 1] - nums[i] < min_diff){
                min_diff = nums[i + k - 1] - nums[i];
            }
        }

        return min_diff;
    }
};