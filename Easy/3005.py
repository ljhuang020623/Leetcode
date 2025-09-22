from typing import List
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        dict = {val: 0 for val in nums}
        result = 0
        for val in nums:
            dict[val] += 1
        max_freq = max(dict.values())
        for key, value in dict.items():
            if value == max_freq:
                result += max_freq
        return result

if __name__ == '__main__': 
    sol = Solution()
    test = [[1,2,2,3,1,4], [1,2,3,4,5]]
    for nums in test:
        ans = sol.maxFrequencyElements(nums)
        print(ans)
