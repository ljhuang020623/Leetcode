#include <vector>

using namespace std;




class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int m = queries.size(), n = queries[0].size();
        for (int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
        
            for (int idx = l; idx <= r; idx += k){
                nums[idx] = (1LL * nums[idx] * v) % mod;    
            }
            
        }

        long long ans = 0;
        for (auto& x : nums){
            ans ^= x;
        }
        return ans;
    }
};