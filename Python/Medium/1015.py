class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        length = 0
        rem = 0
        while True:
            rem = (rem * 10 + 1) % k
            length += 1
            if rem == 0:
                return length
            
sol = Solution()
tests = [1, 2, 3]
for k in tests:
    ans = sol.smallestRepunitDivByK(k)
    print(ans)