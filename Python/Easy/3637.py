from typing import List
class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        i = 0

        # increasing 
        while i < n - 1 and nums[i] < nums[i + 1]:
            i += 1
        p = i
        if i == 0:
            return False
        
        # decreasing
        while i < n - 1 and nums[i] > nums[i + 1]:
            i += 1
        q = i
        if i == p:
            return False
        
        # increasing
        while i < n - 1 and nums[i] < nums[i + 1]:
            i += 1
        if i == q or i != n - 1:
            return False
        return True
