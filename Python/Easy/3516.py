class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        if abs(x - z) == abs(y - z):
            return 0
        elif abs(x - z) < abs(y - z):
            return 1
        else:
            return 2

if __name__ == '__main__': 
    sol = Solution()
    tests = [(2,7,4), (2,5,6), (1,5,3)]
    for x, y, z in tests:
        ans = sol.findClosest(x, y, z)
        print(ans)
