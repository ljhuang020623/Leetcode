#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = INT_MAX;
        for (auto& x : nums){
            if (abs(x - 0) < abs(result)){
                result = x;
            }else if (abs(x - 0) == abs(result)){
                result = max(result, x);
            }
        }
        return result;
    }
};