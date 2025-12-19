from typing import List
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = 0
        k = 1
        ans += k

        for i in range(1, len(prices)):
            if prices[i] == prices[i - 1] - 1:
                k += 1
            else:
                k = 1
            ans += k
        return ans 
sol = Solution()
tests = [[3,2,1,4], [8,6,7,7], [1]]
for prices in tests:
    ans = sol.getDescentPeriods(prices)
    print(ans)