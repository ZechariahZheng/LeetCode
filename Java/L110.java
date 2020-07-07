public class L110 {
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        return Math.abs(heigh(root.left)-heigh(root.right))<2 && isBalanced(root.left) && isBalanced(root.right);
    }

    private int heigh(TreeNode root) {
        if (root == null) {
            return -1;
        }
        return 1+Math.max(heigh(root.left), heigh(root.right));
    }
}