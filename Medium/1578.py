from typing import List 
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        total = 0
        prev_max = neededTime[0]
        for i in range(1, len(colors)):
            if colors[i] == colors[i - 1]:
                total += min(prev_max, neededTime[i])
                prev_max = max(prev_max, neededTime[i])
            else:
                prev_max = neededTime[i]
        return total

if __name__ == '__main__': 
    sol = Solution()
    tests = [("abaac", [1,2,3,4,5]), ("abc", [1,2,3]), ("aabaa", [1,2,3,4,1])]
    for colors, neededTime in tests:
        ans = sol.minCost(colors, neededTime)
        print(ans)