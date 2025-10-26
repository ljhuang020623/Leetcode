class Solution:
    def removeZeros(self, n: int) -> int:
        total = 0
        if n == 0:
            return n
        sign = 1 if n > 0 else -1
        place = 1
        while n > 0:
            d = n % 10 
            if d != 0:
                total += d * place
                place *= 10
            n //= 10
        return sign * total


if __name__ == '__main__': 
    sol = Solution()
    tests = [1020030, 1, 11, 111]
    for n in tests:
        ans = sol.removeZeros(n) 
        print(ans)