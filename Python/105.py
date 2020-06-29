from typing import List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    
    def buildCore(self, preorder: List[int], preStart: int, preEnd: int, inorder: List[int], inStart: int, inEnd: int) -> TreeNode:
        # 根节点
        root = TreeNode(preorder[preStart])

        # 是否长度为1
        if preStart==preEnd:
            return root
        
        # 中序遍历中得到左子树的长度
        rootIndex = inStart
        while preorder[preStart]!=inorder[rootIndex] and rootIndex<inEnd:
            rootIndex += 1
        leftLength = rootIndex-inStart

        #重建左右子树
        if leftLength > 0:
            root.left = self.buildCore(preorder, preStart+1, preStart+leftLength, inorder, inStart, rootIndex-1)
        if leftLength < preEnd-preStart:
            root.right = self.buildCore(preorder, preStart+leftLength+1, preEnd, inorder, rootIndex+1, inEnd)
        
        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder is None or inorder is None or len(preorder) == 0:
            return None
        return self.buildCore(preorder, 0, len(preorder)-1, inorder, 0, len(inorder)-1)
