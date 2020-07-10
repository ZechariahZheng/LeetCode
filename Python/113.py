from typing import List
import copy

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        result = []
        if root is None:
            return result
        resultTmp = []; Tmp = [0]
        self.func(root, sum, Tmp, result, resultTmp)

        return result
    
    def func(self, root: TreeNode, sum: int, Tmp: List[int], result: List[List[int]], resultTmp: List[int]):
        if root.left is None and root.right is None:
            Tmp[0] += root.val
            resultTmp.append(root.val)
            if Tmp[0] == sum:
                resultT = copy.deepcopy(resultTmp)
                result.append(resultT)
            return
        Tmp[0] += root.val
        resultTmp.append(root.val)
        t = Tmp[0]
        resultT = copy.deepcopy(resultTmp)
        if root.left is not None:
            self.func(root.left, sum, Tmp, result, resultTmp)
        Tmp[0] = t
        if root.right is not None:
            self.func(root.right, sum, Tmp, result, resultT)


