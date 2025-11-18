from typing import List 

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        
if __name__ == '__main__': 
    sol = Solution()
    tests = [([1,1,2,2,3,4,2,3], 6, 2), ([3,8,7,8,7,5], 2, 2)]
    for List, k, x in tests:
        ans = sol.findXSum(List, k, x)
        print(ans)
