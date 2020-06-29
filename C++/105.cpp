#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
思路：先从先序遍历中确定根节点，再从中序遍历中确定左右树的长度，其中先序遍历中根节点的下一个
便是左节点，再经过左子树长度的节点之后，便是右节点；
依次类推
*/
class Solution {
public:
    TreeNode *buildCore(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
        //前序遍历第一个节点是根节点
        int rootValue = preorder.at(preStart);
        TreeNode *root = new TreeNode(rootValue);

        //前序序列只有根节点
        if (preStart == preEnd) {
            return root;
        }
            
        //遍历中序序列，找到根节点的位置
        int rootInorder = inStart;
        while (inorder.at(rootInorder)!=rootValue && rootInorder<=inEnd) {
            rootInorder++;
        }

        //左子树的长度
        int leftLength = rootInorder-inStart;
        //前序序列中左子树的最后一个节点
        int leftPreEnd = preStart+leftLength;
        int leftInEnd = inStart+leftLength;

        //左子树非空
        if (leftLength > 0) {
            //重建左子树
            root->left = buildCore(preorder, preStart+1, leftPreEnd, inorder, inStart, leftInEnd);
        }
        //右子树非空
        if (leftLength < preEnd-preStart) {
            //重建右子树
            root->right = buildCore(preorder, leftPreEnd+1, preEnd, inorder, rootInorder+1, inEnd);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        return buildCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};