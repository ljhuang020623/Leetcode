from typing import Optional, List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []
        def dfs(node, curr_sum, path):
            if node is None:
                return
            curr_sum += node.val
            path.append(node.val)
            # Leaf node
            if node.left is None and node.right is None:
                if curr_sum == targetSum:
                    result.append(path.copy())

            dfs(node.right, curr_sum, path)
            dfs(node.left, curr_sum, path)
            path.pop()
        dfs(root, 0, [])
        return result
if __name__ == '__main__': 
    sol = Solution()
    tests = [([5,4,8,11,None,13,4,7,2,None,None,5,1], 22), ([1,2,3], 5), ([1,2], 0)]
    for root, targetSum in tests:
        ans = sol.pathSum(root, targetSum)
        print(ans)
