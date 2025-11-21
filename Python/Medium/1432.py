class Solution:
    def maxDiff(self, num: int) -> int:
        s = str(num)
        def make_max(s):
            for char in s:
                if char != '9':
                    return int(s.replace(char, '9'))
            return int(s)
        def make_min(s):
            if s[0] != '1':
                return int(s.replace(s[0], '1'))
            for i in s[1:]:
                if i not in ['0', '1']:
                    return int(s.replace(i, '0'))
            return int(s)
        return make_max(s) - make_min(s)

if __name__ == '__main__': 
    sol = Solution()
    test = [555,9,123456,123,111,1101057]
    for i in test:
        ans = sol.maxDiff(i)
        print(ans)
