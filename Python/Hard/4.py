from typing import List
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        # numList: the merged list 
        numList = nums1 + nums2
        numList.sort()
        return (len(numList) - 1) // 2 if len(numList) % 2 != 0 else len
        # first use binary search to sort the merged list then find the median value in sorted list 
        #[1, 2, 1, 2]
        

if __name__ == '__main__': 
    sol = Solution()
    tests = []
    for nums1, nums2 in tests:
        ans = sol.findMedianSortedArrays(nums1, nums2)
        print(ans)
