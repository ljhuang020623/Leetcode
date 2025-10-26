class Solution:
    def totalMoney(self, n: int) -> int:
        base = 28
        q = n // 7
        r = n % 7
        sum_weeks = 28 * q + ((7 * q * (q - 1)) / 2)
        sum_lefts = r * ((1 + q) + (r + q)) / 2
        return sum_weeks + sum_lefts

if __name__ == '__main__': 
    sol = Solution()
    tests = [4, 10, 20]
    for n in tests:
        ans = sol.totalMoney(n)
        print(ans)
