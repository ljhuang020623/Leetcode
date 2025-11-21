from typing import List 
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        ops = 0
        m, n = len(grid), len(grid[0])
        for c in range(n):
            prev = grid[0][c]
            for r in range(1, m):
                curr = grid[r][c]
                if curr <= prev:
                    ops += (prev - curr) + 1
                    curr += (prev - curr) + 1
                prev = curr
        return ops



if __name__ == '__main__': 
    sol = Solution()
    tests = [[[3,2],[1,3],[3,4],[0,1]], [[3,2,1],[2,1,0],[1,2,3]]]
    for grid in tests:
        ans = sol.minimumOperations(grid)
        print(ans)
