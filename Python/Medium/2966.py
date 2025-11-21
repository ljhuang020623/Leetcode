from typing import List
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        temp, result = [], []
        nums.sort()
        for i in nums:
            temp.append(i)
            if len(temp) == 3:
                result.append(temp)
                if temp[-1] - temp[0] > k:
                    return []
                temp = []
        return result

            




        # [1,3,4,8,7,9,3,5,1]
        # [1,1,3,3,4,5,7,8,9]

        #[2,2,2,2,4,5]
        #

if __name__ == '__main__': 
    sol = Solution()
    tests = [([1,3,4,8,7,9,3,5,1], 2),([2,4,2,2,5,2], 2), ([4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], 14)]
    for nums, k in tests:
        ans = sol.divideArray(nums, k)
        print(ans)
