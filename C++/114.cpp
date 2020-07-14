#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*二叉树展开为链表
思路：按后序遍历定以一个变量记录当前的节点，阿然后把下一个节点的右节点设置成记录的节点，，，以此类推。
*/
class Solution {
private:
    TreeNode *pre = NULL;
public:
    void flatten(TreeNode* root) {
        if (root != NULL) {
            flatten(root->right);
            flatten(root->left);
            if (pre == NULL) {
                pre = root;
            }
            else {
                root->left = NULL;
                root->right = pre;
                pre = root;
            }
        }
    }
};