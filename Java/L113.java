import java.util.*;

public class L113 {
    static class T {
        int tmp; 
    }
    public static List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        List<Integer> resultTmp = new ArrayList<>();
        T t = new T();
        t.tmp = 0;
        func(root, sum, t, result, resultTmp);
        return result;
    }

    static void func(TreeNode root, int sum, T t, List<List<Integer>> result, List<Integer> resultTmp) {
        if (root.left==null && root.right==null) {
            t.tmp += root.val;
            resultTmp.add(root.val);
            if (t.tmp == sum) {
                List<Integer> resultT = new ArrayList<>();
                for (Integer a: resultTmp) {
                    resultT.add(a);
                }
                result.add(resultT);
            }
            return;
        }
        t.tmp += root.val;
        int n = t.tmp;
        resultTmp.add(root.val);
        List<Integer> resultT = new ArrayList<>();
        for (Integer a: resultTmp) {
            resultT.add(a);
        }
        if (root.left != null) {
            func(root.left, sum, t, result, resultTmp);
        }
        t.tmp = n;
        if (root.right != null) {
            func(root.right, sum, t, result, resultT);
        }
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        a.left = b;
        a.right = c;

        List<List<Integer>> result = pathSum(a, 3);
        System.out.println(result);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }