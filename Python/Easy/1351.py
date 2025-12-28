from typing import List
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        m, n = len(grid), len(grid[0])
        # r -> row, c -> column
        r, c = 0, n - 1
        while r < m and c >= 0 :
            if grid[r][c] < 0:
                ans += (m - r)
                c -= 1
            else:
                r += 1
        return ans
