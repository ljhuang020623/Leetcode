#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // 2D prefix sum in place 
        // Do the calculation in place 
        // Time Complexity: O(m * n), Space Complexity: O(1)
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0){} 
                else if (i == 0){
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0){
                    grid[i][j] += grid[i - 1][j];
                }else {
                    grid[i][j] += (grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1]);
                }
                if (grid[i][j] <= k){
                    ans++;
                }
            }
        }
        return ans;
        // Time Complexity: O(m * n), Space Complexity: O(m * n), space not optimal
        // int m = grid.size(), n = grid[0].size();
        // int ans = 0;
        // vector<vector<int>> prefix_sum(m, vector<int>(n));
        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         if (i == 0 && j == 0){
        //             prefix_sum[i][j] = grid[i][j];
        //         }else if (i == 0){
        //             prefix_sum[i][j] = prefix_sum[i][j - 1] + grid[i][j];
        //         }else if (j == 0){
        //             prefix_sum[i][j] = prefix_sum[i - 1][j] + grid[i][j];
        //         }else {
        //             prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + grid[i][j];
        //         }
        //         if (prefix_sum[i][j] <= k){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
    }
};