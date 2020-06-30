from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def func(self):
        print("hello world")
    
    def buildCore(self, inorder: List[int], inStart: int, inEnd: int, postorder: List[int], postStart: int, postEnd: int) -> TreeNode:
        root = TreeNode(postorder[postEnd])

        if postEnd == postStart:
            return root
        
        rootVal = postorder[postEnd]
        rootIndex = inStart
        while inorder[rootIndex]!=rootVal and rootIndex<inEnd:
            rootIndex += 1
        leftLength = rootIndex-inStart

        if leftLength > 0:
            root.left = self.buildCore(inorder, inStart, rootIndex-1, postorder, postStart, postStart+leftLength-1)
        if leftLength < postEnd-postStart:
            root.right = self.buildCore(inorder, rootIndex+1, inEnd, postorder, postStart+leftLength, postEnd-1)
        return root
        
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if inorder is None or postorder is None or len(postorder)==0:
            return None
        return self.buildCore(inorder, 0, len(inorder)-1, postorder, 0, len(postorder)-1)