# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node, currentNumber):
            if node is None:
                return 0
            
            currentNumber = (currentNumber << 1) | node.val
            
            if node.left is None and node.right is None:
                return currentNumber
            
            leftSum = dfs(node.left, currentNumber)
            rightSum = dfs(node.right, currentNumber)
            
            return leftSum + rightSum
        
        return dfs(root, 0)