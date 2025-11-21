class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # '1 / 2 = 0.5', 
        # '2 / 1 = 2', 
        # '4 / 333 = 0.(012)'
        dict = {}
        result = []
        index = 2
        if numerator == 0:
            return '0'
        negative = numerator * denominator < 0
        numerator = abs(numerator)
        denominator = abs(denominator)

        integer = numerator // denominator
        result.append(str(integer))
        remainder = numerator % denominator
        # first condition to return where remainder is 0
        if remainder == 0:
            result_str = ''.join(result)
            return '-' + result_str if negative else result_str
        else:
            result.append('.')
        while remainder != 0:
            # second condition to return where repeat take place
            if remainder in dict.keys():
                start = dict[remainder]
                result.insert(start, '(')
                result.append(')')
                result_str = ''.join(result)
                return '-' + result_str if negative else result_str
            dict[remainder] = index
            index += 1
            remainder *= 10
            quotient = remainder // denominator
            result.append(str(quotient))
            remainder %= denominator
        result_str = ''.join(result)
        return '-' + result_str if negative else result_str
    

if __name__ == '__main__': 
    sol = Solution()    
    tests = [(1, 2), (2, 1), (4, 333), (1, 6)]
    for numerator, denominator in tests:
        ans = sol.fractionToDecimal(numerator, denominator)
        print(ans)