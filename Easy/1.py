from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, num in enumerate(nums):
            pair = target - num
            if pair in dict:
                return [i, dict[pair]]
            dict[num] = i
if __name__ == '__main__': 
    sol = Solution()
    tests  = [([2,7,11,15], 9), ([3,2,4], 6), ([3,3], 6)]
    for nums, target in tests:
        ans = sol.twoSum(nums, target)
        print(ans)

            