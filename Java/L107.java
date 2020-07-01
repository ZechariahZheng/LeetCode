import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class L107 {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        List<Integer> resultTmp = new ArrayList<>();
        List<TreeNode> tmpStack = new ArrayList<>();
        tmpStack.add(root);
        
        while (tmpStack.size() > 0) {
            for (TreeNode tmp: tmpStack) {
                resultTmp.add(tmp.val);
            }
            result.add(resultTmp);
            resultTmp = new ArrayList<>();

            List<TreeNode> tmpS = new ArrayList<>(tmpStack);
            tmpStack = new ArrayList<>();
            for (TreeNode tmp: tmpS) {
                if (tmp.left != null) {
                    tmpStack.add(tmp.left);
                }
                if (tmp.right != null) {
                    tmpStack.add(tmp.right);
                }
            }
        }
        Collections.reverse(result);
        return result;
    }
}