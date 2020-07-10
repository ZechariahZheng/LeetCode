#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*二叉树路径总和II
使用先序遍历的思路，遍历整个二叉树，其中达到叶子节点时，判断和是否等于目标
同时在遍历的过程中，维持一个列来保存经过的节点，该列在节点返回时，会吐出该
节点
 */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
    }
};