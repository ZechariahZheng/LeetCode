class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        tmp = [0]
        return self.func(root, sum, tmp)
        
    def func(self, root: TreeNode, sum: int, tmp: List) -> bool:
        if root.left is None and root.right is None:
            if tmp[0]+root.val == sum:
                return True
            return False
        tmp[0] += root.val
        a = tmp[0]
        leftFlag = False; rightFlag = False
        if root.left is not None:
            leftFlag = self.func(root.left, sum, tmp)
        tmp[0] = a
        if root.right is not None:
            rightFlag = self.func(root.right, sum, tmp)
        return leftFlag or rightFlag
            