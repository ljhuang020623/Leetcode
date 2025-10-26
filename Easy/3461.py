class Solution:
    def hasSameDigits(self, s: str) -> bool:
        result = ''
        while len(s) > 2:
            for i in range(len(s) - 1):
                result += str((int(s[i]) + int(s[i + 1])) % 10)
            s = result
            result = ''
        return s[0] == s[1]

if __name__ == '__main__': 
    sol = Solution()
    tests = ["3902", "34789"]
    for s in tests:
        ans = sol.hasSameDigits(s)
        print(ans)