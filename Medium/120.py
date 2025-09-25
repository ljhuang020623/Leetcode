# DP problem
# According to CLRS DP algorithm, follow a sequence of 4 steps:
# 1. Charecterize the structure of an optimal solution
# 2. Recursively define a value of an optimal solution
# 3. Compute the value of an optimal solution, typically in a bottom-up fashion.
# 4. Construct an optimal solution from computed information.


from typing import List
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # DP Bottom up iterate from the 2nd last row all the way to the top row
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1])
        return triangle[0][0]
    
if __name__ == '__main__': 
    sol = Solution()
    tests = [[[2],[3,4],[6,5,7],[4,1,8,3]], [[-10]], [[0]], [[0], [0, 0]], [[2],[-3,4],[100,99,7],[4,1,-8,3]], [[3],[3,3],[3,3,3],[3,3,3,3],[3,3,3,3,3],[3,3,3,3,3,3],[3,3,3,3,3,0,3]]]
    for triangle in tests:
        ans = sol.minimumTotal(triangle)
        print(ans)
