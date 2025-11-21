from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return 
        left_inverted = self.invertTree(root.left)
        right_inverted = self.invertTree(root.right)
        root.left, root.right = right_inverted, left_inverted
        return root
    


if __name__ == '__main__': 
    sol = Solution()
    ans = sol.invertTree([4,2,7,1,3,6,9])
    print(ans)