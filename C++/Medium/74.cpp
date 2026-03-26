#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // 2D
        int left = 0, right = m * n - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            int num = matrix[mid / n][mid % n];
            if (num == target){
                return true;
            }else if (num > target){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return false;
        
    }
};