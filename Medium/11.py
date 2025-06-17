from typing import List
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        result = []
        while left <= right:
            x = min(height[left], height[right])
            result.append(x * (right - left))
            if x == height[left]:
                left += 1
            else:
                right -= 1
        max = 0
        for x in result:
            if x > max:
                max = x
        return max


if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,8,6,2,5,4,8,3,7], [1,1], [1,2,1], [1,3,2,5,25,24,5]]
    for test in tests:
        ans = sol.maxArea(test)
        print(ans)