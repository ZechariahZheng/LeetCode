#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
从中序与后序遍历序列构造二叉树
思路：从中序遍历中找到左子树的长度，然后在后序遍历中根据左子树的长度，确定左右子节点
递归之
*/
class Solution {
public:
    TreeNode *buildCore(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
        //根节点
        TreeNode *root = new TreeNode(postorder.at(postEnd));

        //判断是否结束
        if (postEnd == postStart) {
            return root;
        }

        //从中序遍历中得到左子树的长度
        int rootVal = postorder.at(postEnd);
        int rootIndex = inStart;
        while (rootVal!=inorder.at(rootIndex) && rootIndex<inEnd) {
            rootIndex++;
        }
        int leftLength = rootIndex-inStart;
        //重建左右子树
        if (leftLength > 0) {
            root->left = buildCore(inorder, inStart, rootIndex-1, postorder, postStart, postStart+leftLength-1);
        }
        if (leftLength < postEnd-postStart) {
            root->right = buildCore(inorder, rootIndex+1, inEnd, postorder, postStart+leftLength, postEnd-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0) {
            return NULL;
        }
        return buildCore(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};

void preSearch(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << endl;
    preSearch(root->left);
    preSearch(root->right);
}

int main()
{
    int a[] = {9,3,15,20,7};
    vector<int> inorder(begin(a), end(a));
    int b[] = {9,15,7,20,3};
    vector<int> postorder(begin(b), end(b));
    Solution s;
    cout << "hello world" << endl;
    TreeNode *root = s.buildTree(inorder, postorder);
    preSearch(root);
}