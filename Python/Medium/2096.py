from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        


if __name__ == '__main__': 
    sol = Solution()
    tests = [([5,1,2,3,None,6,4], 3, 6), 
             ([2,1], 2, 1), 
             ([1,None,10,12,13,4,6,None,15,None,None,5,11,None,2,14,7,None,8,None,None,None,9,3], 6, 15),
    ]
    for root, startValue, destValue in tests:
        ans = sol.getDirections(tests)
        print(ans)
        