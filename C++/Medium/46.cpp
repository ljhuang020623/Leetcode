#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, nums, temp);
        return ans;
    }

    vector<int> backtrack(int idx, vector<int>& nums, vector<int>& temp){
        if (idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            backtrack(idx + 1, nums, temp);
            temp.pop_back();
        }
    }

};