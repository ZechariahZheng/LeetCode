public class L114 {
    TreeNode pre = null;
    public void flatten(TreeNode root) {
        if (root != null) {
            flatten(root.right);
            flatten(root.left);
            if (pre == null) {
                pre = root;
            } else {
                root.left = null;
                root.right = pre;
                pre = root;
            }
        }
    }
}