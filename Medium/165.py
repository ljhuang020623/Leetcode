class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # split string by delimiter '.' and then compare each by each
        v1 = [int(s) for s in version1.split('.')]
        v2= [int(s) for s in version2.split('.')]
        max_len = max(len(v1), len(v2))
        v1.extend([0] * (max_len - len(v1)))
        v2.extend([0] * (max_len - len(v2)))
        for i in range(max_len):
            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1
        return 0
    
if __name__ == '__main__': 
    sol = Solution()
    tests = [("1.2", "1.10"), ("1.01","1.001"), ("1.0", "1.0.0.0")]
    for version1, version2 in tests:
        ans = sol.compareVersion(version1, version2)
        print(ans)
