from typing import List
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        result = []
        n = len(nums)
        r = 0
        for i, j in enumerate(nums):
            if j == key:
                # upper bound 
                upper = min(n - 1, i + k)
                # pointer for avoid adding repetitive
                r = max(r, i - k)
                while r <= upper:
                    result.append(r)
                    r += 1
        return result
            


if __name__ == '__main__': 
    sol = Solution()
    tests = [([3,4,9,1,3,9,5], 9, 1)]
    for nums, key, k in tests:
        ans = sol.findKDistantIndices(nums, key, k)
        print(ans)


# nums: [3,4,9,1,3,9,5], key: 9, k: 1
# return [1,2,3,4,5,6]