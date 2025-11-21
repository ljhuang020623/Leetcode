class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        # Base case
        if n <= 0:
            return False
        if n == 1:
            return True
        if n % 3 == 0:
            return self.isPowerOfThree(n // 3)
        return False



        
if __name__ == '__main__': 
    sol = Solution()
    test = [27, 0, -1]
    for n in test:
        ans = sol.isPowerOfThree(n)
        print(ans)