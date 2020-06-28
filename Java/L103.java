import java.util.List;
import java.util.ArrayList;

/*二叉树的锯齿形层次遍历
思路：采用先序遍历二叉树，同时用两个队列来保存两个方向的值*/
public class L103 {
    

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<TreeNode> leftQueue = new ArrayList<>();
        List<TreeNode> rightQueue = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> resultTmp = new ArrayList<>();
        if (root == null)
            return result;
        leftQueue.add(root);
        if (root.left != null)
            rightQueue.add(root.left);
        if (root.right != null)
            rightQueue.add(root.right);
        while (!leftQueue.isEmpty() || !rightQueue.isEmpty()) {
            //输出值
            if (!leftQueue.isEmpty()) {
                for (TreeNode tmp: leftQueue) {
                    resultTmp.add(tmp.val);
                }
                result.add(resultTmp);
                resultTmp = new ArrayList<>();
            }
            if (!rightQueue.isEmpty()) {
                for (int i = rightQueue.size()-1; i >= 0; i--) {
                    resultTmp.add(rightQueue.get(i).val);
                }
                result.add(resultTmp);
                resultTmp = new ArrayList<>();
            }
            //移动队列
            leftQueue = new ArrayList<>();
            if (!rightQueue.isEmpty()) {
                for (TreeNode tmp: rightQueue) {
                    if (tmp.left != null) {
                        leftQueue.add(tmp.left);
                    }
                    if (tmp.right != null) {
                        leftQueue.add(tmp.right);
                    }
                }
            }
            rightQueue = new ArrayList<>();
            if (!leftQueue.isEmpty()) {
                for (TreeNode tmp: leftQueue) {
                    if (tmp.left != null) {
                        rightQueue.add(tmp.left);
                    }
                    if (tmp.right != null) {
                        rightQueue.add(tmp.right);
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        TreeNode d = new TreeNode(4);
        TreeNode e = new TreeNode(5);
        a.left = b; 
        b.left = c;
        c.left = d;
        d.left = e;
        List<List<Integer>> result = zigzagLevelOrder(a);
        System.out.println(result);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}