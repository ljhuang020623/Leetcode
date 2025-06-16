class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        def make_max(s):
            for char in s:
                if char != '9':
                    return int(s.replace(char, '9'))
            return int(s)
        def make_min(s):
            for char in s:
                if char != '0':
                    return int(s.replace(char, '0'))
            return int(s)
        return make_max(s) - make_min(s)
if __name__ == '__main__': 
    sol = Solution()
    test = [11891, 90]
    for i in test:
        ans = sol.minMaxDifference(i)
        print(ans)
