from typing import  List, Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev, curr = dummy, head
        while curr:
            if curr.val in nums:
                prev.next = curr.next
                curr = curr.next
            else:
                prev = curr
                curr = curr.next
        return dummy.next
        

if __name__ == '__main__': 
    sol = Solution()
    tests = [([1,2,3], [1,2,3,4,5]), ([1], [1,2,1,2,1,2]), ([5], [1,2,3,4])]
    for nums, head in tests:
        ans = sol.modifiedList(nums, head)
        print(ans)