/*java 类可以直接访问内部类的属性*/
public class L112 {
    class Tmp {
        int val;
        void setVal(int a) {
            val = a;
        }
        int getVal() {
            return val;
        }
    }
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        Tmp t = new Tmp();
        t.setVal(0);
        return func(root, sum, t);
    }
    
    boolean func(TreeNode root, int sum, Tmp tmp) {
        if (root.left==null && root.right==null) {
            if (tmp.val+root.val == sum) {
                return true;
            }
            return false;
        }
        tmp.val += root.val;
        int a = tmp.val;
        boolean leftFlag = false, rightFlag = false;
        if (root.left != null) {
            leftFlag = func(root.left, sum, tmp);
        }
        tmp.val = a;
        if (root.right != null) {
            rightFlag = func(root.right, sum, tmp);
        }
        return leftFlag || rightFlag;
    }
}


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }