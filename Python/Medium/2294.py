from typing import List 
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        nums.sort()
        start, count = 0, 1
        for i in range(1, len(nums)):
            if nums[i] - nums[start] > k:
                start = i
                count += 1
            if nums[i] - nums[start] <= k:
                continue
        return count

if __name__ == '__main__': 
    sol = Solution()
    tests = [([3,6,1,2,5], 2), ([1,2,3], 1), ([2,2,4,5], 0)]
    for nums, k in tests:
        ans = sol.partitionArray(nums, k)
        print(ans)

# [1,2,3,5,6], 2
# [1,4,5,6], 2



