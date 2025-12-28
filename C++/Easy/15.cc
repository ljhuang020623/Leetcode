#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i <  n - 2; i++){
            int l{i + 1}, r{n - 1};
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (l < r){
                int s = nums[i] + nums[l] + nums[r];
                if (s == 0){
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]){
                        r--;
                    }
                } else if(s < 0){
                    l++;
                } else{
                    r--;
                }
            }
        }
        return result;
    }
};