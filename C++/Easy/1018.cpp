#include <iostream>
#include <vector>



class Solution {

public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        std::vector<bool> v;
        long accum = 0;
        for (int i = 0; i < nums.size(); i++){
           accum = accum * 2 + nums[i];
           v.push_back(accum % 5 == 0);
        }
        return v;
    }
};