#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix_prod(n, vector<int>(m, 1));
        vector<vector<int>> ans(n, vector<int>(m, 1));
        const int mod = 12345;
        
        // first pass to get the prefix_prod of each position
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i == 0 && j == 0) continue;
                // the first element of each row in grid
                if (j == 0){
                    prefix_prod[i][j] = (1LL * grid[i - 1][m - 1] * prefix_prod[i - 1][m - 1]) % mod;
                }else {
                    prefix_prod[i][j] = (1LL * grid[i][j - 1] * prefix_prod[i][j - 1]) % mod;
                }
            }
        } 


        int prev = 1;
        // second pass loop from the end of the grid to multiple each position with prefix_prod and record each prev
        for (int i = n - 1; i >= 0; i--){
            for (int j = m - 1; j >= 0; j--){
                ans[i][j] = (1LL * prefix_prod[i][j] * prev) % mod;
                prev = (1LL * prev * grid[i][j]) % mod;
            }
        }
        return ans;

    }
};