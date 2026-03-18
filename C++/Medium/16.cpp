#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;
            while (left < right){
                int tempSum = nums[i] + nums[left] + nums[right];
                if (abs(tempSum - target) < abs(closest - target)){
                    closest = tempSum;
                }
                if (tempSum < target){
                    left++;
                }else if (tempSum > target){
                    right--;
                } else{
                    return tempSum;
                }
            }
        }
        return closest;

    }
};