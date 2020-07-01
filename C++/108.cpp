#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*将有序数组转换为二叉搜索树  
思路：等价于中序遍历重建二叉树
按照二分法的思想，根节点可以为数组的中间节点
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size());
    }

    TreeNode *func(vector<int> &nums, int left, int right) {
        if (left > right)
            return NULL;
        int rootIndex = (left+right)/2;
        int rootVal = nums.at(rootIndex);
        TreeNode *root = new TreeNode(rootVal);
        root->left = func(nums, left, rootIndex-1);
        root->right = func(nums, rootIndex+1, right);
        return root;
    }
};