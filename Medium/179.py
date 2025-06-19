from typing import List
from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        str_nums = [str(n) for n in nums]
        
        def compare(n1, n2):
            if n1 + n2 > n2 + n1:
                return -1
            else:
                return 1
        result = sorted(str_nums, key = cmp_to_key(compare))
        if result[0] == '0':
            return '0'
        return ''.join(result)



if __name__ == '__main__': 
    sol = Solution()
    tests = [[10,2],[3,30,34,5,9], [0,0,0]]
    for nums in tests:
        ans = sol.largestNumber(nums)
        print(ans)
