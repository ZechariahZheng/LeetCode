class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        leftDepth = self.minDepth(root.left)
        rightDepth = self.minDepth(root.right)
        if root.left is None or root.right is None:
            return leftDepth+rightDepth+1
        return min(leftDepth, rightDepth)+1