#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int max_len = 0;
        int zerocount = 0;
        for (int right = 0; right < n; right++){
            if (nums[right] == 0){
                zerocount++;
            }
            while (zerocount > 1){
                if (nums[left] == 0){
                    zerocount--;
                }
                left++;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};