from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums is None:
            return None
        return self.func(nums, 0, len(nums)-1)
    
    def func(self, nums: List[int], left: int, right: int) -> TreeNode:
        if left > right:
            return None
        rootIndex = (left+right)//2
        root = TreeNode(nums[rootIndex])
        root.left = self.func(nums, left, rootIndex-1)
        root.right = self.func(nums, rootIndex+1, right)
        return root