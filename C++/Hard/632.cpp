#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // nums = [[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]
        vector<pair<int, int>> arr;
        pair<int, int> res;
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[i].size(); j++){
                arr.push_back({nums[i][j], i});
            }
        }
        // pair sort by first first
        sort(arr.begin(), arr.end());
        // arr = [(0, 1), (4, 0), (5, 2), (9, 1), (10, 0), (12, 1), (15, 0), (18, 2), (20, 1), (22, 2), (24, 0), (26, 0), (30, 2)]
        vector<int> appear(k, 0);
        int min_len = INT_MAX;
        int covered = 0;

        int left = 0;

        for (int right = 0; right < arr.size(); right++){
            int idx = arr[right].second;
            // the k distinct list are all covered
            if (appear[idx] == 0) covered++;
            // appear document the same idx appearance in the window
            appear[idx]++;

            while (covered == k){
                int temp_len = arr[right].first - arr[left].first;
                if (temp_len < min_len){
                    res = {arr[left].first, arr[right].first};
                    min_len = temp_len;
                }
                int left_idx = arr[left].second;
                appear[left_idx]--;
                if (appear[left_idx] == 0) covered--;
                left++;
            }            
        }
        return {res.first, res.second};

    }
};