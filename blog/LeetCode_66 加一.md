## LeetCode_66 加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

**思路：从尾到头遍历数组，如果数组中的数字不为9，直接加一返回，如果为9，变为0。如果全部是9，则重新声明一个长度+1的数组**

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        //跳转for循环，说明数字全部都是9
        int[] result = new int[digits.length+1];
        result[0] = 1;
        return result;
    }
}
```

