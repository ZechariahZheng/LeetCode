#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*平衡二叉树
求出左右子树的高度，递归判断每个节点的高度差是否小于或等于1
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        int leftHigh = 0, rightHigh = 0, tmp = 0;
        func(root->left, &leftHigh, &tmp);
        tmp = 0;
        func(root->right, &rightHigh, &tmp);
        if (abs(leftHigh-rightHigh) <= 1) {
            return isBalanced(root->right) && isBalanced(root->left);
        } else {
            return false;
        }      
    }

    void func(TreeNode *node, int *high, int *tmp) {
        if (node == NULL) {
            if (*tmp > *high) {
                *high = *tmp;
            }
            return;
        }
        *tmp += 1;
        int t = *tmp;
        func(node->left, high, &t);
        t = *tmp;
        func(node->right, high, &t);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);
    TreeNode f(4);
    TreeNode g(4);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    d.left = &f;
    d.right = &g;

    Solution s;
    s.isBalanced(&a);

    return 0;
}