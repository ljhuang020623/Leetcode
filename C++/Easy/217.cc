#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i : nums){
            // find return iterator
            if (seen.count(i)){
                return true;
            } else{
                seen.insert(i);
            }
        }
        return false;
    }
};