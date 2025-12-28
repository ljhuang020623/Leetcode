#include <vector>
using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m{(int)grid.size()}, n{(int)grid[0].size()};
        int r{0}, c{n - 1};
        int ans{0};
        while (r < m && c >= 0){
            if (grid[r][c] < 0){
                ans += (m - r);
                c -= 1;
            } else{
                r += 1;
            }
        }
        return ans;

    }
};