#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i){
            int remain{target - nums[i]};
            // found remain in seen
            if (seen.find(remain) != seen.end()){
                return {seen[remain], i};
            }
            // not found in seen
            seen[nums[i]] = i;
        }
        return {};
    }
};