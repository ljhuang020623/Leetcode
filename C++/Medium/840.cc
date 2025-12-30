#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int row{static_cast<int>(grid.size())}, column{static_cast<int>(grid[0].size())};
        int result{0};


        // Early exit for rows and columns smaller than 3
        if (row < 3 || column < 3){
            return 0;
        }

        for (int r = 0; r < row - 2; r++){
            for (int c = 0; c < column - 2; c++){
                if (isMagic(grid, r, c)){
                    result += 1;
                }
            }
        }

        return result;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int r, int c){
        if (grid[r + 1][c + 1] != 5){
            return false;
        }
        unordered_set<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = r; i < r + 3; i++){
            for (int j = c; j < c + 3; j++){
                // found grid[i][j] in nums
                if (nums.find(grid[i][j]) != nums.end()){
                    nums.erase(grid[i][j]);
                } else{
                    return false;
                }
            }
        }

        // rows
        if (grid[r][c]   + grid[r][c+1]   + grid[r][c+2]   != 15) return false;
        if (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] != 15) return false;
        if (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] != 15) return false;

        // cols
        if (grid[r][c]   + grid[r+1][c]   + grid[r+2][c]   != 15) return false;
        if (grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] != 15) return false;
        if (grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] != 15) return false;

        // diagonals
        if (grid[r][c]   + grid[r+1][c+1] + grid[r+2][c+2] != 15) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]   != 15) return false;

        return nums.empty();
    }

};




