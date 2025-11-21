from typing import List
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        result = []
        i = len(s)
        if i % k == 0:
            for j in range(0, len(s), k):
                result.append(s[j:j + k])
        else:
            s = s + fill * (k - i % k)
            for j in range(0, len(s), k):
                result.append(s[j:j + k])
        return result



if __name__ == '__main__': 
    sol = Solution()
    tests = [("abcdefghi", 3, 'x'), ("abcdefghij", 3, 'x')]
    for s, k, fill in tests:
        ans = sol.divideString(s, k, fill)
        print(ans)