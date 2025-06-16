from typing import List
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        
        def can_make(limit: int) -> bool:
            cnt = i = 0
            n = len(nums)
            while i < n - 1:
                if nums[i+1] - nums[i] <= limit:
                    i += 2
                    cnt += 1
                else:
                    i += 1
            # if cnt < p then there is no enough pair to do the required compare p pairs
            return cnt >= p
        
        low, high = 0, nums[-1] - nums[0]
        while low < high:
            mid = (low + high) // 2
            if can_make(mid):
                high = mid
            else:
                low = mid + 1
        return low



if __name__ == "__main__":
    sol = Solution()
    ans = sol.minimizeMax([3,4,2,3,2,1,2], 3)
    print(ans)

#[1,2,2,2,3,3,4]
# nums = [1,1,2,3,7,10], p = 2
# In this case we should return max(a, b), where a = |7 - 8|, b = |9 - 10|, max(1, 1) = 1
# 1. sort the array
# 2. find the first pair of numbers and calculate the disctance
# 3. get rid of the first pair of numbers from the nums list and then use binary search for the next 2 smallest number
# [x]