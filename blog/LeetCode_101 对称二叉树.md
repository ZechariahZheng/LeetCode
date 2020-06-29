## LeetCode_101 对称二叉树

 给定一个二叉树，检查它是否是镜像对称的。 

**思路：递归**

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return ismirror(root, root);
    }
    private boolean ismirror(TreeNode p, TreeNode q) {
        if (p==null && q==null) {
            return true;
        }
        if (p==null || q==null) {
            return false;
        }
        if (p.val == q.val) {
            return ismirror(p.left, q.right) && ismirror(p.right, q.left);
        }
        return false;
    }
}
```

