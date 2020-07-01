
public class L108 {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null) {
            return null;
        }
        return func(nums, 0, nums.length-1);
    }

    private TreeNode func(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }
        int rootIndex = (left+right)/2;
        TreeNode root = new TreeNode(nums[rootIndex]);
        root.left = func(nums, left, rootIndex-1);
        root.right = func(nums, rootIndex+1, right);
        return root;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }