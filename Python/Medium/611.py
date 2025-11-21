from typing import List
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums)<=2:
            return 0
        count=0
        for k in range(2,len(nums)):
            i,j=0,k-1
            while i<j:
                if nums[i]+nums[j]>nums[k]:
                    count+=(j-i)
                    j-=1
                else:
                    i+=1
        return count

if __name__ == '__main__': 
    sol = Solution()
    tests = [[2,2,3,4], [4,2,3,4]]
    for nums in tests:
        ans = sol.triangleNumber(nums)
        print(ans)
