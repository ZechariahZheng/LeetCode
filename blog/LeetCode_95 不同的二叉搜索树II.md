## LeetCode_95 不同的二叉搜索树II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /      /        / \      \
     3     2     1      1   3      2
    /     /         \                     \
   2     1         2                     3



对于连续整数序列`[left, right]`中的一点`i`，若要生成以`i`为根节点的BST，则有如下规律：

- `i`左边的序列可以作为左子树结点，且左儿子可能有多个，所以有`vector left_nodes = generate(left, i - 1);`；
- `i`右边的序列可以作为右子树结点，同上所以有`vector right_nodes = generate(i + 1, right);`；
- 产生的以当前`i`为根结点的BST（子）树有`left_nodes.size() * right_nodes.size()`个，遍历每种情况，即可生成以`i`为根节点的BST序列；
- 然后以`for`循环使得`[left, right]`中每个结点都能生成子树序列。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n==0)
            return new LinkedList<TreeNode>();
        return generateTrees(1,n);
    }
    public List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> res = new LinkedList<TreeNode>();
        if (start > end) {
            res.add(null);
            return res;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> subLeftTree = generateTrees(start, i-1);
            List<TreeNode> subRightTree = generateTrees(i+1, end);
            for (TreeNode left: subLeftTree) {
                for (TreeNode right: subRightTree) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    res.add(node);
                }
            }
        }
        return res;
    }
}
```

