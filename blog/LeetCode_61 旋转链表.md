## LeetCode_61 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

**思路：确定需要移动的位数k，真正需要移动的位数为k%len，接着确定新的头和尾，以及交界处；同时注意k%len==0时直接返回**

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return null;
        if (k==0)
            return head;
        List<ListNode> all = new ArrayList<>();
        ListNode tmp = head;
        while (tmp != null) {
            all.add(tmp);
            tmp = tmp.next;
        }
        int len = all.size();
        if (k%len == 0)
            return head;
        int index = len-k%len ;
        //新的头
        ListNode result = all.get(index);
        int last;
        if (index > 0)
            last = index-1;
        else
            last = len-1;
        if (last != len-1) {
            //新的尾
            ListNode tail = all.get(last);
            tail.next = null;
            //交接处
            ListNode x = all.get(len-1);
            x.next = all.get(0);
        }
        
        return result;
    }
}
```

