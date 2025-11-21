from typing import List 
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        X = 0
        for i in operations:
            if i == '--X' or i == 'X--':
                X -= 1
            else:
                X += 1
        return X
if __name__ == '__main__': 
    sol = Solution()
    tests = [["--X","X++","X++"], ["++X","++X","X++"], ["X++","++X","--X","X--"]]
    for operations in tests:
        ans = sol.finalValueAfterOperations(operations)
        print(ans)
