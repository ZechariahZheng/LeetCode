#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        int tmp = 0;
        return func(root, sum, &tmp);
    }

    bool func(TreeNode *root, int sum, int *tmp) {
        if (root->left==NULL && root->right==NULL) {
            if (*tmp+root->val == sum) {
                return true;
            }
            return false;
        }
        *tmp += root->val;
        int t = *tmp;
        bool leftFlag = false, rightFlag = false;
        if (root->left != NULL) {
            leftFlag = func(root->left, sum, tmp); 
        }    
        *tmp = t;
        if (root->right != NULL) {
            rightFlag = func(root->right, sum, tmp);
        }
        
        return leftFlag || rightFlag;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution s;
    if (s.hasPathSum(&a, 3))
        cout << "hello world" << endl;
}