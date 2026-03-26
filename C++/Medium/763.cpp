#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // s = "ababcbacadefegdehijhklij"
        // s = "eccbbbbdec"
        vector<int> ans;
        int n = s.length();
        unordered_map<int, int> last_idx;

        for (int i = 0; i < n; i++){
            last_idx[s[i]] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < n; i++){
            end = max(end, last_idx[s[i]]);
            if (i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;

    }
};