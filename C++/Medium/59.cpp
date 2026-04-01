#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int num = 1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                matrix[top][j] = num++;
            }

            for (int i = top + 1; i <= bottom; i++) {
                matrix[i][right] = num++;
            }

            if (top < bottom) {
                for (int j = right - 1; j >= left; j--) {
                    matrix[bottom][j] = num++;
                }
            }

            if (left < right) {
                for (int i = bottom - 1; i > top; i--) {
                    matrix[i][left] = num++;
                }
            }

            top++;
            bottom--;
            left++;
            right--;
        }

        return matrix;
    }
};