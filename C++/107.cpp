#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
思路：层次遍历，使用栈保存，结果最后倒序即可
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        vector<TreeNode*> tmpStack;
        vector<int> resultTmp;
        tmpStack.push_back(root);

        while (tmpStack.size() > 0) {
            for (TreeNode *tmp: tmpStack) {
                resultTmp.push_back(tmp->val);
            }
            result.push_back(resultTmp);
            resultTmp.clear();

            vector<TreeNode*> tmpS(tmpStack);
            tmpStack.clear();
            for (TreeNode *tmp: tmpS) {
                if (tmp->left != NULL)
                    tmpStack.push_back(tmp->left);
                if (tmp->right != NULL)
                    tmpStack.push_back(tmp->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};