from typing import List 

class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        result = [0] * len(nums)
        accum = 0
        for index, bit in enumerate(nums):
            accum = accum * 2 + bit
            if accum % 5 == 0:
                result[index] = True
            else:
                result[index] = False
        return result