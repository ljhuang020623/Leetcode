#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    // its is either 1, 3, 5, 7 or 2, 4, 6, 8 
    // the subproblems are just simply even or odd index only
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        // dp[i] = maximum money can rob from house 0...i
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};