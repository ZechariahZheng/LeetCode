class Solution:
    def __init__(self)
        self.pre = None
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is not None:
            self.flatten(root.right)
            self.flatten(root.left)
            if self.pre is None:
                self.pre = root
            else:
                root.left = None
                root.right = self.pre
                self.pre = root
