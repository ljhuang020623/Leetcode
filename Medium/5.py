class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxlen = 0
        result = ''
        for c in range(len(s)):
            l, r = c, c 
            while l >= 0 and r <= len(s) - 1 and s[l] == s[r]:
                l -= 1
                r += 1
            if r - l + 1 > maxlen:
                maxlen = r - l + 1
                result = s[l + 1: r]

            l, r = c, c + 1
            while l >= 0 and r <= len(s) - 1 and s[l] == s[r]:
                l -= 1
                r += 1
            if r - l + 1 > maxlen:
                maxlen = r - l + 1
                result = s[l + 1: r]
        return result
if __name__ == '__main__': 
    sol = Solution()
    tests = ["cbbd","babad"]
    for s in tests:
        ans = sol.longestPalindrome(s)
        print(ans)
