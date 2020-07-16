import java.util.ArrayList;
import java.util.List;

public class L117 {
    public static Node connect(Node root) {
        if (root == null) {
            return root;
        }
        root.next = null;
        List<Node> stack1 = new ArrayList<>();
        List<Node> stack2 = new ArrayList<>();
        if (root.left != null) {
            stack1.add(root.left);
        }
        if (root.right != null) {
            stack1.add(root.right);
        }
        Node tmp, pre;
        while (stack1.size()>0 || stack2.size()>0) {
            pre = null;
            while (stack1.size() > 0) {
                tmp = stack1.get(0);
                System.out.println("stack1: "+tmp.val);
                if (pre == null) {
                    pre = tmp;
                } else {
                    pre.next = tmp;
                    pre = tmp;
                }
                stack1.remove(0);
                if (tmp.left != null) {
                    stack2.add(tmp.left);
                }
                if (tmp.right != null) {
                    stack2.add(tmp.right);
                }
            }
            pre = null;
            while (stack2.size() > 0) {
                tmp = stack2.get(0);
                System.out.println("stack2: "+tmp.val);
                if (pre == null) {
                    pre = tmp;
                } else {
                    pre.next = tmp;
                    pre = tmp;
                }
                stack2.remove(0);
                if (tmp.left != null) {
                    stack1.add(tmp.left);
                }
                if (tmp.right != null) {
                    stack2.add(tmp.right);
                }
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        Node e = new Node(5);
        a.left = b;
        a.right = c;
        b.left = d;
        b.right = e;
        connect(a);
    }
}

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};