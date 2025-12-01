from typing import List 
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        total = 0
        left, right = 0, len(nums) - 1
        nums.sort(key=abs)
        list = []
        for i in range(len(nums)):
            if i % 2 == 0:
                list.append(nums[right])
                right -= 1
            else:
                list.append(nums[left])
                left += 1
        for i, num in enumerate(list):
            sign = 1 if i % 2 == 0 else -1
            total += (sign * (num ** 2))
        return total
       


if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,2,3], [1,-1,2,-2,3,-3]]
    for nums in tests:
        ans = sol.maxAlternatingSum(nums)
        print(ans)
