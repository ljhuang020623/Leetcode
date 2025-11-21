from typing import List
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        best_diff = -1
        smallest = nums[0]
        for i in range(len(nums)):
            if nums[i] > smallest :
                best_diff = max(best_diff, nums[i] - smallest)
            else:
                smallest = nums[i]
        return best_diff
