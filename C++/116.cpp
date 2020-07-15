#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*填充每个节点的下一个右侧节点指针
思路：按照二叉树层次打印的思路，在层次遍历的过程中设置next
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        root->next = NULL;
        queue<Node *> stack1;
        queue<Node *> stack2;
        if (root->left != NULL) {
            stack1.push(root->left);
        }
        if (root->right != NULL) {
            stack1.push(root->right);
        }
        
        Node *tmp = NULL, *pre = NULL;
        while (stack1.size()>0 || stack2.size()>0) {
            pre = NULL;
            while(stack1.size() > 0) {
                tmp = stack1.front();
                if (pre == NULL) {
                    pre = tmp;
                } else {
                    pre->next = tmp;
                    pre = tmp;
                }
                stack1.pop();
                if (tmp->left) {
                    stack2.push(tmp->left);
                }
                if (tmp->right) {
                    stack2.push(tmp->right);
                }         
            }
            pre = NULL;
            while(stack2.size() > 0) {
                tmp = stack2.front();
                if (pre == NULL) {
                    pre = tmp;
                } else {
                    pre->next = tmp;
                    pre = tmp;
                }
                stack2.pop();
                if (tmp->left) {
                    stack1.push(tmp->left);
                }
                if (tmp->right) {
                    stack1.push(tmp->right);
                }
                
            }
        }
        return root;
    }
};

int main() {
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    Node f(6);
    Node g(7);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    Solution s;
    s.connect(&a);

    return 0;
}