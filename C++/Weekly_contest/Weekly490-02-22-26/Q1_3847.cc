#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        unordered_map<int, int> mp = {{1, 0}, {0, 0}};
        int game = 1, turns = 1;
        for (auto& i : nums){
            if (game % 6 == 0){
                turns ^= 1;
            }
            if (i % 2 != 0){
                turns ^= 1;
            }
            mp[turns] += i;
            game++;
        }
        return mp[1] - mp[0];
    }
};