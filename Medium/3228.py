class Solution:
    def maxOperations(self, s: str) -> int:
        total, count_ones = 0, 0
        for i in range(len(s) - 1):
            if s[i] == '1' and s[i + 1] == '0':
                count_ones += 1
                total += count_ones
                continue
            if s[i] == '1':
                count_ones += 1
        return total
        

if __name__ == '__main__': 
    sol = Solution()
    tests = ["1001101", "00111"]
    for s in tests:
        ans = sol.maxOperations(s)
        print(ans)

# The intuition for this problem is that when ever u encounter 1s u accumulate them and when u encounter 0 every previous 1 has
# to cross the zeros block eventually thus u push the count of the 1s block to the total count.2