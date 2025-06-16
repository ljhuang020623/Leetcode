from typing import List
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        curr = 1
        k -= 1
        while k > 0:
            if curr * 10 <= n:
                curr *= 10
            elif curr % 10 != 9 and curr + 1 <= n:
                curr += 1
            else:
                while curr // 10 % 10 == 9:
                    curr //= 10
                curr = curr // 10 + 1
            k -= 1
        return curr


if __name__ == "__main__":
    sol = Solution()
    ans = sol.findKthNumber(13, 2)
    print(ans)