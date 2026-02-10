#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); i++){
            unordered_set<int> odd_st, even_st;
            for (int j = i; j < (int)nums.size(); j++){
                if (nums[j] % 2 == 0) even_st.insert(nums[j]);
                if (nums[j] % 2 != 0) odd_st.insert(nums[j]);
                if (even_st.size() == odd_st.size()){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;

    }
};