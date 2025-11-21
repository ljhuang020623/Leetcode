from typing import List
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        # Create a array 0 for even 1 for odd in nums
        P = [n % 2 for n in nums]
        even_count = P.count(0)
        odd_count = P.count(1)
        first_ans = max(even_count, odd_count)

        def longest_alt(start_parity: int) -> int:
            expected = start_parity
            length = 0
            for p in P:
                if p == expected:
                    length += 1
                    expected ^= 1
            return length
        alt_0 = longest_alt(0)
        alt_1 = longest_alt(1)
        second_ans = max(alt_0, alt_1)
        return max(first_ans, second_ans)

if __name__ == '__main__': 
    sol = Solution()
    test = [[1,2,3,4], [1,2,1,1,2,1,2], [1,3]]
    for nums in test:
        ans = sol.maximumLength(nums)
        print(ans)




# (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2. 
# 2 possible outcome: (sub[x] + sub[x+1]) % 2 == 0 or (sub[x] + sub[x+1]) % 2 == 1
