from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        


if __name__ == '__main__': 
    sol = Solution()
    tests = [([[1,1],[2,2],[3,3]]), ([[6,2],[4,4],[2,6]]), ([[3,1],[1,3],[1,1]])]
    for points in tests:
        ans = sol.numberOfPairs(points)
        print(ans)
