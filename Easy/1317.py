from typing import List
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        k = 1
        while(k <= n):
            if self.has_zero(k) or self.has_zero(n - k):
                k += 1
            else:
                return [k, n - k]
        return 0
    def has_zero(self, num: int) -> bool:
        while num > 0:
            digit = num % 10
            if digit == 0:
                return True
            num //= 10
        return False
if __name__ == '__main__': 
    sol = Solution()
    tests = [2, 11, 1010]
    for n in tests:
        ans = sol.getNoZeroIntegers(n)
        print(ans)