#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // total
        long long total = 0;
        for (int r = 0; r < m; r++){
            total += accumulate(grid[r].begin(), grid[r].end(), 0LL);
        }

        // vertical
        long long topSum = 0;
        for (int r = 0; r < m - 1; r++){
            topSum += accumulate(grid[r].begin(), grid[r].end(), 0LL);
            if (topSum == total - topSum){
                return true;
            }
        }

        long long leftSum = 0;
        for (int c = 0; c < n - 1; c++){
            for (int r = 0; r < m; r++){
                leftSum += grid[r][c];
            }
            if (leftSum == total - leftSum){
                return true;
            }
        }
        


        return false;
    }
};