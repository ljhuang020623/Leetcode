from typing import List 
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        result = 0
        n = len(points)
        for a in range(n):
            for b in range(a + 1, n):
                for c in range(b + 1, n):
                    area = 0.5 * abs(
                                    points[a][0] * (points[b][1] - points[c][1]) +
                                    points[b][0] * (points[c][1] - points[a][1]) +
                                    points[c][0] * (points[a][1] - points[b][1])
                                    )
                    if area > result:
                        result = area
        return result
                                  


if __name__ == '__main__': 
    sol = Solution()
    tests = [[[0,0],[0,1],[1,0],[0,2],[2,0]], [[1,0],[0,0],[0,1]]]
    for points in tests:
        ans = sol.largestTriangleArea(points)
        print(ans)
