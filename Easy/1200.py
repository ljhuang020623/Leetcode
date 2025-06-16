from typing import List
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        r.sort()
        low, high = 0, arr[-1] - arr[0]
        while low < high:
            mid = (low + high) // 2

