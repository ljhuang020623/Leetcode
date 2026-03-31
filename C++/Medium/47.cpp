#include <unordered_set>

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used){
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++){
            if (seen.count(nums[i])) continue;
            if (used[i]) continue;

            temp.push_back(nums[i]);
            used[i] = true;
            seen.insert(nums[i]);

            backtrack(nums, temp, used);

            temp.pop_back();
            used[i] = false;
        }
        
    }

};