class Solution:
    def largestGoodInteger(self, num: str) -> str:
        goodint = ['999', '888', '777', '666', '555', '444','333', '222', '111', '000']
        for i in goodint:
            if i in num:
                return i
        return ''

if __name__ == '__main__': 
    sol = Solution()
    tests = ["6777133339", "2300019", "42352338"]
    for num in tests:
        ans = sol.largestGoodInteger(num)
        print(ans)