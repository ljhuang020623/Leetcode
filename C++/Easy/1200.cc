#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;

        int min_diff{abs(arr[1] - arr[0])};
        for (int i = 0; i < arr.size() - 1; i++){
            int diff = arr[i + 1] - arr[i];

            if (diff < min_diff){
                min_diff = diff;
                result.clear();
                result.push_back({arr[i], arr[i + 1]});
            } else if (diff == min_diff){
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};