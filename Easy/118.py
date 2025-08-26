from typing import List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1]]
        if numRows == 1:
            return result
        count = 2
        while count <= numRows:
            prev = result[-1]
            row = [1]
            for i in range(1, len(prev)):
                row.append(prev[i - 1] + prev[i])
            row.append(1)
            result.append(row)
            count += 1
        return result


if __name__ == '__main__': 
    sol = Solution()
    tests = [5, 1]
    for test in tests:
        ans = sol.generate(test)
        print(ans)
