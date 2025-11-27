# the thought is that if it is divisible by three jsut take it and if it is mod = 1 then u have to find a maximum mod = 2 number to pair it 
# same for the other way around
from typing import List
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        sorted(nums)
        sum = 0
        dp = 
        for i in range(len(nums) - 1, 0, -1):
            for j in range(i - 1, -1, -1):
                if 
            