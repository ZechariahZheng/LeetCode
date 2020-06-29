## LeetCode_92 反转链表II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

思路：

第一步：找到待反转节点的前一个节点。
第二步：反转m到n这部分。
第三步：将反转的起点的next指向反转的后面一部分。
第四步：将第一步找到的节点指向反转以后的头节点。
如下图所示：

![](E:\文档\blog\pic\反转链表.png)

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode res = new ListNode(0);
        res.next = head;
        ListNode node = res;
        //找到需反转的那一段的上一个节点
        for (int i = 1; i < m; i++) {
            node = node.next;
        }
        //node.next就是需要反转的这段的起点
        ListNode nextHead = node.next;
        ListNode next = null;
        ListNode pre = null;
        //反转m到n这一段
        for (int i = m; i <= n; i++) {
            next = nextHead.next;
            nextHead.next = pre;
            pre = nextHead;
            nextHead = next;
        }
        //将反转的起点的next指向next
        node.next.next = next;
        //需反转的那一段的上一个节点的next节点指向反转后链表的头节点
        node.next = pre;
        return res.next;
    }
}
```

