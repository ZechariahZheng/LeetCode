#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*有序列表转换为高度二叉搜索树
使用二分法将列表转换为二叉搜索树，类似于108题
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return func(nums, 0, nums.size()-1);
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