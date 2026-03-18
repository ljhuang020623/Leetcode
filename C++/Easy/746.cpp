#include <vector>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i] = min cost to reach i
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++){
            // at index i it can be either 2 steps from cost[i - 2] or 1 step from cost[i - 1]
            dp[i] = min(cost[i] + dp[i - 2], cost[i] + dp[i - 1]);
        }     
        return min(dp[n - 1], dp[n - 2]);
    }
};