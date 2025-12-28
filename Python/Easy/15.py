from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            if nums[i] > 0:
                break
            if nums[i] == nums[i - 1] and i > 0:
                continue
            while l < r:
                if nums[i] + nums[l] + nums[r] == 0:
                    result.append([nums[i], nums[l], nums[r]])
                    l += 1 
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1
                elif nums[l] + nums[i] + nums[r] < 0:
                    l += 1
                else:
                    r -= 1
        return result
