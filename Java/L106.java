
public class L106 {
    private TreeNode buildCore(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, int postEnd) {
        //根节点
        TreeNode root = new TreeNode(postorder[postEnd]);

        if (postEnd == postStart) {
            return root;
        }

        //从中序遍历中得到左子树的长度
        int rootVal = postorder[postEnd];
        int rootIndex = inStart;
        while (inorder[rootIndex]!=rootVal && rootIndex<inEnd) {
            rootIndex++;
        }
        int leftLength = rootIndex-inStart;

        //重建左右子树
        if (leftLength > 0) {
            root.left = buildCore(inorder, inStart, rootIndex-1, postorder, postStart, postStart+leftLength-1);
        }
        if (leftLength < postEnd-postStart) {
            root.right = buildCore(inorder, rootIndex+1, inEnd, postorder, postStart+leftLength, postEnd-1);
        }
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder==null || postorder==null || inorder.length==0) {
            return null;
        }
        return buildCore(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }
}

