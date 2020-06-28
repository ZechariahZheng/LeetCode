from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        leftQueue = []; rightQueue = []; result = []; resultTmp = []
        if root is None:
            return result
        leftQueue.append(root)
        if root.left is not None:
            rightQueue.append(root.left)
        if root.right is not None:
            rightQueue.append(root.right)
        
        while len(leftQueue)>0 or len(rightQueue)>0:
            # 输出            
            for i in range(len(leftQueue)):
                resultTmp.append(leftQueue[i].val)
            if len(resultTmp) > 0:
                result.append(resultTmp)
            resultTmp = []
            for i in range(len(rightQueue)-1, -1, -1):
                resultTmp.append(rightQueue[i].val)
            if len(resultTmp) > 0:
                result.append(resultTmp)
            resultTmp = []
            # 移动
            leftQueue = []
            for i in range(len(rightQueue)):
                if rightQueue[i].left is not None:
                    leftQueue.append(rightQueue[i].left)
                if rightQueue[i].right is not None:
                    leftQueue.append(rightQueue[i].right)
            rightQueue = []
            for i in range(len(leftQueue)):
                if leftQueue[i].left is not None:
                    rightQueue.append(leftQueue[i].left)
                if leftQueue[i].right is not None:
                    rightQueue.append(leftQueue[i].right)
        return result

if __name__ == "__main__":
    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    d = TreeNode(15)
    e = TreeNode(7)
    a.left = b
    a.right = c
    c.left = d
    c.right = e
    s = Solution()
    result = s.zigzagLevelOrder(a)
    print(result)

        