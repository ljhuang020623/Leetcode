from typing import List 
class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total = sum(nums)
        accumulate = 0
        count = 0
        for i in range(len(nums) - 1):
            accumulate += nums[i]
            total -= nums[i]
            if abs(accumulate - total) % 2 == 0:
                count += 1
        return count 
    