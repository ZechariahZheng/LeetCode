from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 二叉树的层次遍历 II
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root is None:
            return result
        resultTmp = []
        tmpStack = [root]

        while len(tmpStack) > 0:
            for tmp in tmpStack:
                resultTmp.append(tmp.val)
            result.append(resultTmp)
            resultTmp = []
            tmpS = tmpStack
            tmpStack = []
            for tmp in tmpS:
                if tmp.left is not None:
                    tmpStack.append(tmp.left)
                if tmp.right is not None:
                    tmpStack.append(tmp.right)
        result.reverse()
        return result