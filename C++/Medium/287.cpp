#include <vector>

using namespace std;

class Solution {
public:
    // Floyd's cycle detection 
    // 
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            // means both are in cycle
            if (slow == fast) break;
        }

        int finder = nums[0];
        if (finder == slow) return slow;
        while (true){
            finder = nums[finder];
            slow = nums[slow];
            if (finder == slow) return slow;
        }
    }
};