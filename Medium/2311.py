class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        value = 0
        bit = 0
        length = 0
        # iterate bits from right to left 
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '0':
                length += 1
            else:
                if value + (1 << bit) <= k:
                    value += 1 << bit
                    length += 1
            bit += 1
        return length



if __name__ == '__main__': 
    sol = Solution()
    tests = [("1001010", 5), ("00101001", 1)]
    for s, k in tests:
        ans = sol.longestSubsequence(s, k)
        print(ans)



# iterate through s from right to left then take it if the total is under k until the total is over or equal k
# then u simply take all the leading zeros contain in s to make it the longes subsequence