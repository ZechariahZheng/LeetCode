## LeetCode_67 二进制求和

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

**思路：从尾到头遍历两个字符串，同时设置进位标志，遍历相加即可**

```java
class Solution {
    public String addBinary(String a, String b) {
        int n = Math.min(a.length(), b.length());
        int i = a.length()-1, j = b.length()-1;
        int jin = 0, tmpA = 0, tmpB = 0;
        StringBuilder sb = new StringBuilder();
        while (i>=0 || j>=0) {
            if (i >= 0)
                    tmpA = a.charAt(i)-'0';
            else
                tmpA = 0;
            if (j >= 0)
                    tmpB = b.charAt(j)-'0';
            else
                tmpB = 0;
            int sum = tmpA+tmpB+jin;
            if (sum >= 2) {
                sb.append(sum-2);
                jin = 1;
            }
            else {
                sb.append(sum);
                jin = 0;
            }
            i--;
            j--;
        }
        if (jin == 1)
            sb.append(1);
        return sb.reverse().toString();
    }
}
```

