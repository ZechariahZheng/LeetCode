## LeetCode_102 二叉树的锯齿层次遍历

 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 

**思路：采用先序遍历二叉树，同时用两个队列来保存两个方向的值**

```c++
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
```

```java
import java.util.List;
import java.util.ArrayList;

/*二叉树的锯齿形层次遍历
思路：采用先序遍历二叉树，同时用两个队列来保存两个方向的值*/
public class L103 {
    

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<TreeNode> leftQueue = new ArrayList<>();
        List<TreeNode> rightQueue = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> resultTmp = new ArrayList<>();
        if (root == null)
            return result;
        leftQueue.add(root);
        if (root.left != null)
            rightQueue.add(root.left);
        if (root.right != null)
            rightQueue.add(root.right);
        while (!leftQueue.isEmpty() || !rightQueue.isEmpty()) {
            //输出值
            if (!leftQueue.isEmpty()) {
                for (TreeNode tmp: leftQueue) {
                    resultTmp.add(tmp.val);
                }
                result.add(resultTmp);
                resultTmp = new ArrayList<>();
            }
            if (!rightQueue.isEmpty()) {
                for (int i = rightQueue.size()-1; i >= 0; i--) {
                    resultTmp.add(rightQueue.get(i).val);
                }
                result.add(resultTmp);
                resultTmp = new ArrayList<>();
            }
            //移动队列
            leftQueue = new ArrayList<>();
            if (!rightQueue.isEmpty()) {
                for (TreeNode tmp: rightQueue) {
                    if (tmp.left != null) {
                        leftQueue.add(tmp.left);
                    }
                    if (tmp.right != null) {
                        leftQueue.add(tmp.right);
                    }
                }
            }
            rightQueue = new ArrayList<>();
            if (!leftQueue.isEmpty()) {
                for (TreeNode tmp: leftQueue) {
                    if (tmp.left != null) {
                        rightQueue.add(tmp.left);
                    }
                    if (tmp.right != null) {
                        rightQueue.add(tmp.right);
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        TreeNode d = new TreeNode(4);
        TreeNode e = new TreeNode(5);
        a.left = b; 
        b.left = c;
        c.left = d;
        d.left = e;
        List<List<Integer>> result = zigzagLevelOrder(a);
        System.out.println(result);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
```

```python
from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        leftQueue = []; rightQueue = []; result = []; resultTmp = []
        if root is None:
            return result
        leftQueue.append(root)
        if root.left is not None:
            rightQueue.append(root.left)
        if root.right is not None:
            rightQueue.append(root.right)
        
        while len(leftQueue)>0 or len(rightQueue)>0:
            # 输出            
            for i in range(len(leftQueue)):
                resultTmp.append(leftQueue[i].val)
            if len(resultTmp) > 0:
                result.append(resultTmp)
            resultTmp = []
            for i in range(len(rightQueue)-1, -1, -1):
                resultTmp.append(rightQueue[i].val)
            if len(resultTmp) > 0:
                result.append(resultTmp)
            resultTmp = []
            # 移动
            leftQueue = []
            for i in range(len(rightQueue)):
                if rightQueue[i].left is not None:
                    leftQueue.append(rightQueue[i].left)
                if rightQueue[i].right is not None:
                    leftQueue.append(rightQueue[i].right)
            rightQueue = []
            for i in range(len(leftQueue)):
                if leftQueue[i].left is not None:
                    rightQueue.append(leftQueue[i].left)
                if leftQueue[i].right is not None:
                    rightQueue.append(leftQueue[i].right)
        return result

if __name__ == "__main__":
    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    d = TreeNode(15)
    e = TreeNode(7)
    a.left = b
    a.right = c
    c.left = d
    c.right = e
    s = Solution()
    result = s.zigzagLevelOrder(a)
    print(result)

        
```

