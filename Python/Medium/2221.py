from typing import List
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        else:
            for i in range(len(nums) - 1):
                nums[i] = (nums[i] + nums[i + 1]) % 10
            return self.triangularSum(nums[:-1])

if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,2,3,4,5], [1,2,3,4], [5]]
    for nums in tests:
        ans = sol.triangularSum(nums)
        print(ans)
