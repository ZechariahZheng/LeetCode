import java.util.List;
import java.util.ArrayList;

public class L109 {
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        while (head != null) {
            nums.add(head.val);
            head = head.next;
        }
        return func(nums, 0, nums.size()-1);
    }

    private TreeNode func(List<Integer> nums, int left, int right) {
        if (left > right) {
            return null;
        }
        int rootIndex = (left+right)/2;
        TreeNode root = new TreeNode(nums.get(rootIndex));
        root.left = func(nums, left, rootIndex-1);
        root.right = func(nums, rootIndex+1, right);
        return root;
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}