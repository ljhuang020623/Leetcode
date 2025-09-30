from typing import List 
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        result = 0
        k = len(nums) - 1
        n = len(nums)
        for i in range(n - 2):
            a, b, c = nums[i], nums[i + 1], nums[i + 2]
            if b + c > a:
                return a + b + c
        return 0
        

[2,3,3,6]
if __name__ == '__main__': 
    sol = Solution()
    tests = [[2,1,2], [1,2,1,10], [3,6,2,3]]
    for nums in tests:
        ans = sol.largestPerimeter(nums)
        print(ans)
