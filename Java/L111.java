public class L111 {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left==null && root.right==null) {
            return 1;
        }
        int leftDepth = minDepth(root.left);
        int rightDepth = minDepth(root.right);
        if (root.left==null || root.right==null) {
            return leftDepth+rightDepth+1;
        }
        return Math.min(leftDepth, rightDepth)+1;
    }
}