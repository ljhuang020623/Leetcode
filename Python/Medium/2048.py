class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        # Check whether x is balanced
        def is_balanced(x: int) -> bool:
            count = [0] * 10 
            while x:
                d = x % 10
                if d == 0:
                    return False
                count[d] += 1
                x //= 10
            for i in range(1, 10):
                if count[i] != i and count[i] != 0:
                    return False
            return True
        
        n += 1
        while True:
            if is_balanced(n):
                return n
            n += 1

if __name__ == '__main__': 
    sol = Solution()
    tests = [1, 1000, 3000]
    for n in tests:
        ans = sol.nextBeautifulNumber(n)
        print(ans)