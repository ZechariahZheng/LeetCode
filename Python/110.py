class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return abs(self.getHeight(root.left)-self.getHeight(root.right))<2 and self.isBalanced(root.left) and self.isBalanced(root.right)
    
    def getHeight(self, root: TreeNode) -> int:
        if root is None:
            return -1
        return 1+max(self.getHeight(root.left), self.getHeight(root.right))