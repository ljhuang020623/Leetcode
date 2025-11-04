from typing import List 
from collections import Counter
class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        result = [0] * (n - k + 1)
        # subarray size is k
        def Xsum(list: List[int], x: int) -> List[int]:
            sum = 0
            counts = Counter(list)
            # kv[1] is the count, kv[0] is value, 
            # 1. -kv[1] is we want to sort it in count descending
            # 2. if -kv[1] is the same then compare the -kv[0] we want the larger value hence value descending as well
            topx = sorted(counts.items(), key = lambda kv: (-kv[1], -kv[0]))[:x]
            for k, v in topx:
                sum += (k * v)
            return sum
        
        for i in range(0, n - k + 1):
            result[i] = Xsum(nums[i:i + k], x)
        return result



if __name__ == '__main__': 
    sol = Solution()
    tests = [([1,1,2,2,3,4,2,3], 6, 2), ([3,8,7,8,7,5], 2, 2)]
    for nums, k, x in tests:
        ans = sol.findXSum(nums, k, x)
        print(ans)
 