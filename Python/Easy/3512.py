from typing import List
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        total = sum(x for x in nums)
        return total % k
