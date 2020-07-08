#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left==NULL && root->right==NULL) {
            return 1;
        } 
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (root->left==NULL || root->right==NULL) {
            return leftDepth+rightDepth+1;
        }
        return min(leftDepth, rightDepth)+1;
    }

}; 

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    Solution s;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.right = &e;
    cout << s.minDepth(&a) << endl;
    return 0;
}