from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        index = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[index] = nums[i]
                index += 1
        return nums
        
if __name__ == '__main__': 
    sol = Solution()
    test = [[1,1,2], [0,0,1,1,1,2,2,3,3,4]]
    for i in test:
        ans = sol.removeDuplicates(i)
        print(ans)

print(4 %  4)