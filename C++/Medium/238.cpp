#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_prod(n, 1);
        vector<int> ans(n, 1);

        // first pass run the left_prod to get the prefix product of each position
        for (int i = 1; i < n; i++){
            left_prod[i] = left_prod[i - 1] * nums[i - 1];
        }


        // second pass will loop through nums from right and multiply each position with the left_prod and prev
        int prev = 1;
        for (int i = n - 1; i >= 0; i--){
            ans[i] = left_prod[i] * prev;
            prev *= nums[i];
        }
        return ans;
        
    }
};