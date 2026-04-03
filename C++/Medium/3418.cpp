#include <vector>

using namespace std;



// dp[i][j][k] = the maximum amount of money a robot can collect by reaching [i][j] and having neutralized k robbers
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(3, INT_MIN))
        );


        if (coins[0][0] >= 0){
            // coins[0][0] is positive
            dp[0][0][0] = coins[0][0];
        }else {
            // negative 
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++){
                    if (coins[i][j] >= 0){
                        if (i > 0 && dp[i - 1][j][k] != INT_MIN){
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                        }
                        if (j > 0 && dp[i][j - 1][k] != INT_MIN){
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                        }
                    }else {
                        // do not neutralize
                        if (i > 0 && dp[i - 1][j][k] != INT_MIN){
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                        }
                        if (j > 0 && dp[i][j - 1][k] != INT_MIN){
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                        }

                        // when k > 0
                        if (k > 0){
                            if (i > 0 && dp[i - 1][j][k - 1] != INT_MIN){
                                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                            }
                            if (j > 0 && dp[i][j - 1][k - 1] != INT_MIN){
                                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                            }
                        }
                    }
                }              
            }
        }
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});

    }
};