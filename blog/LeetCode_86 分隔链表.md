## LeetCode_86 分隔链表

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

**思路：使用两个链表，其中一个链表保存小于x的值，另一个链表保存大于等于x的值，最后将两个链表拼接即可**

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
    public ListNode partition(ListNode head, int x) {
        ListNode min = new ListNode(0);
        ListNode max = new ListNode(0);
        ListNode tmp2 = min;
        ListNode tmp1 = max;
        
        while (head != null) {
            if (head.val >= x) {
                tmp1.next = head;
                head = head.next;
                tmp1 = tmp1.next;
                tmp1.next = null;
            } else {
                tmp2.next = head;
                head = head.next;
                tmp2 = tmp2.next;
                tmp2.next = null;
            }
        }
        tmp2.next = max.next;
        return min.next;
    }
}
```

