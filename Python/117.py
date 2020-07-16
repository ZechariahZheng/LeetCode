# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        root.next = None
        stack1 = []; stack2 = []
        if root.left is not None:
            stack1.append(root.left)
        if root.right is not None:
            stack1.append(root.right)
        pre = None; tmp = None
        while len(stack1)>0 or len(stack2)>0:
            pre = None
            while len(stack1)>0:
                tmp = stack1[0]
                if pre is None:
                    pre = tmp
                else:
                    pre.next = tmp
                    pre = tmp
                stack1.pop(0)
                if tmp.left is not None:
                    stack2.append(tmp.left)
                if tmp.right is not None:
                    stack2.append(tmp.right)
            pre = None
            while len(stack2)>0:
                tmp = stack2[0]
                if pre is None:
                    pre = tmp
                else:
                    pre.next = tmp
                    pre = tmp
                stack2.pop(0)
                if tmp.left is not None:
                    stack1.append(tmp.left)
                if tmp.right is not None:
                    stack1.append(tmp.right)
        return root
