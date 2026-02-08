#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = (int)nums.size();
        int i = 0;

        // increasing 
        while (i < n - 1 && nums[i] < nums[i + 1]){
            i += 1;
        }
        int p = i;
        if (i == 0){
            return false;
        }

        // decreasing
        while (i < n - 1 && nums[i] > nums[i + 1]){
            i += 1;
        }
        int q = i;
        if (i == p){
            return false;
        }

        // increasing
        while (i < n - 1 && nums[i] < nums[i + 1]){
            i += 1;
        }
        if (i == q || i < n - 1){
            return false;
        }

        return true;

    }
};