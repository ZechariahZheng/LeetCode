#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> resultTmp;
        vector<TreeNode*> leftQueue;
        vector<TreeNode*> rightQueue;

        if (root == NULL)
            return result;
        leftQueue.push_back(root);
        if (root->left)
            rightQueue.push_back(root->left);
        if (root->right)
            rightQueue.push_back(root->right);
        while (!leftQueue.empty() || !rightQueue.empty()) {
            // 输出
            if (!leftQueue.empty()) {
                for (TreeNode *tmp: leftQueue) {
                    resultTmp.push_back(tmp->val);
                }
                result.push_back(resultTmp);
                resultTmp.clear();
            }
            if (!rightQueue.empty()) {
                for (int i = rightQueue.size()-1; i >= 0; i--) {
                    resultTmp.push_back(rightQueue.at(i)->val);
                }
                result.push_back(resultTmp);
                resultTmp.clear();
            }
            // 移动
            leftQueue.clear();
            if (!rightQueue.empty()) {
                for (TreeNode *tmp: rightQueue) {
                    if (tmp->left)
                        leftQueue.push_back(tmp->left);
                    if (tmp->right)
                        leftQueue.push_back(tmp->right);
                }
            }
            rightQueue.clear();
            if (!leftQueue.empty()) {
                for (TreeNode *tmp: leftQueue) {
                    if (tmp->left)
                        rightQueue.push_back(tmp->left);
                    if (tmp->right)
                        rightQueue.push_back(tmp->right);
                }
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c (20);
    TreeNode d(15);
    TreeNode e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    Solution *s = new Solution();
    vector<vector<int>> result = s->zigzagLevelOrder(&a);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.at(i).size(); j++) {
            cout << result.at(i).at(j) << " ";
        }
        cout << endl;
    }
}