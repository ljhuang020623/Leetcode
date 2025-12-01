from typing import List
class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums.sort()
        result = []
        max = nums[-1]
        min = nums[0]
        for i in range(min, max + 1):
            if i not in nums:
                result.append(i)
        return result
if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,4,2,5], [7,8,6,9], [5,1]]
    for nums in tests:
        ans = sol.findMissingElements(nums)
        print(ans)
