from typing import List 
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        # the first loop means length 3 to the entire polygon(3 as the base case of the triangle)
        for length in range(3, n + 1):
            # the second loop means the starting point of the vertices in the polygon, 
            # [1, 2, 3, 4, 5], n = 5, length = 3, there are 3 starting point n - length + 1
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')
                # the third loop stands for the diagonal line to partition the polygon
                # note that it is dp[i][k] + dp[k][j] instead of dp[i][k] + dp[k + 1][j] since that the two triangle shares the same vertex on k
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k])
        return dp[0][n - 1]

if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,2,3], [3,7,4,5], [1,3,1,4,1,5]]
    for values in tests:
        ans = sol.minScoreTriangulation(values)
        print(ans)

"""
Model this problem as a matrix-chain multiplication,
values = [1, 2, 3], the polygon is already triangulated return the value of only triange values[0] * values[1] * values[2]
values = [3, 7, 4, 5], there are n - 2 which is 2 subpolygon
"""