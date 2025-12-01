from typing import List
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        abs_nums = [abs(i) for i in nums]
        abs_nums.sort()
        return abs_nums[-1] * abs_nums[-2] * pow(10, 5)
if __name__ == '__main__': 
    sol = Solution()
    tests = [[-5,7,0], [-4,-2,-1,-3], [0,10,0]]
    for nums in tests:
        ans = sol.maxProduct(nums)
        print(ans)
# The idea for this question is that since we are choosing 3 numbers in nums, there are 3 scenarios
# 1. 1 negative, 1 positive: then we can simply choose -pow(10, 5)
# 2. 2 negative: choose pow(10, 5)
# 3. 2 positive: choose pow(10, 5)
# so we know that we dont need to worry about the sign of the numbers as long as its absolute value are 2 largest in nums

