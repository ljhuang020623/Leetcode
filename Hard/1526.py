from typing import List 
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        total = 0
        for i in range(len(target)):
            if i == 0:
                total += target[i]
                break
            if target[i] - target[i - 1] > 0:
                total += target[i] - target[i - 1]
        return total 
    
if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,2,3,2,1], [3,1,1,2], [3,1,5,4,2]]
    for target in tests:
        ans = sol.minNumberOperations(target)
        print(ans)