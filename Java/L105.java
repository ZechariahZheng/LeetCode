public class L105 {
    private TreeNode buildCore(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        //根节点
        TreeNode root = new TreeNode(preorder[preStart]);

        //判断左子树是否长度为1
        if (preStart == preEnd) {
            return root;
        }

        //从中序遍历中得到左子树的长度
        int rootIndex = inStart;
        while (preorder[preStart]!=inorder[rootIndex] && rootIndex<inEnd) {
            rootIndex++;
        }
        int leftLength = rootIndex-inStart;

        //重建左右子树
        if (leftLength > 0) {
            root.left = buildCore(preorder, preStart+1, preStart+leftLength, inorder, inStart, rootIndex-1);
        }
        if (leftLength < preEnd-preStart) {
            root.right = buildCore(preorder, preStart+leftLength+1, preEnd, inorder, rootIndex+1, inEnd);
        }
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder==null || inorder==null || preorder.length==0) {
            return null;
        }
        return buildCore(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }