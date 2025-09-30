from typing import List
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[0] * m for _ in range(n)]
        dp[0][0] = grid[0][0]
        # first row 
        for j in range(1, m):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        # first column
        for i in range(1, n):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
                

        return dp[n - 1][m - 1] 
        
if __name__ == '__main__': 
    sol = Solution()
    tests = [[[1,3,1],[1,5,1],[4,2,1]], [[1,2,3],[4,5,6]]]
    for grid in tests:
        ans = sol.minPathSum(grid)
        print(ans)
