from typing import List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[] for _ in range(numRows)]

        print(dp)


if __name__ == '__main__': 
    sol = Solution()
    tests = [5, 1]
    for test in tests:
        ans = sol.generate(test)
        print(ans)
