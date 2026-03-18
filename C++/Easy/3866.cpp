#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq(n);
        for (auto& x : nums){
            freq[x]++;
        }
        for(auto&x : nums){
            if(x % 2 == 0 && freq[x] == 1){
                return x;
            }
        }
        return -1;
    }
};