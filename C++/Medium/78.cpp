#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(0, nums, temp);         
        return ans;
    }

    void dfs(int idx, vector<int>& nums, vector<int> temp){
        if (idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        // skip nums[idx]
        dfs(idx + 1, nums, temp);

        // take nums[idx]
        temp.push_back(nums[idx]);
        dfs(idx + 1, nums, temp);
    }
};