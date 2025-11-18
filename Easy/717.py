from typing import List 
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        # if i can iterate to the last digit in bits means that it is true
        while i in range(len(bits)):
            if i == len(bits) - 1:
                return True
            if bits[i] == 1:
                i += 2
            elif bits[i] == 0:
                i += 1
        # if i break the loop means that the last character is either 10 or 11 thus last bits can be tww-bit charecter
        return False
if __name__ == '__main__': 
    sol = Solution()
    tests = [[1,0,0], [1,1,1,0]]
    for bits in tests:
        ans = sol.isOneBitCharacter(bits)
        print(ans)

