#include <vector>

using namespace std;

#define pb push_back
#define ll long long

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); mask++){
            vector<int> cur;
            for (int j = 0; j < n; j++){
                if (mask & (1 << j)){
                    cur.pb(nums[j]);
                }
            }
            res.pb(move(cur));
        }
        return res;

    }
};`