from typing import List
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        min_diff = nums[n - 1] - nums[0]
        # base cases
        if k == n:
            return min_diff
        if k == 1:
            return 0

        for i in range(0, n - k + 1):
            if nums[i + k - 1] - nums[i] < min_diff:
                min_diff = nums[i + k - 1] - nums[i]
        return min_diff


      