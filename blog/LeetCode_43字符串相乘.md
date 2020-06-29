[字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

 

示例 1:

 

输入: num1 = "2", num2 = "3"

输出: "6"

示例 2:

 

输入: num1 = "123", num2 = "456"

输出: "56088"

 

思路：先将长的数字乘以短的数字的每一位，然后再将每一位相乘的积相加起来

```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        //判断两个字符串长度大小
        if (num1.length() >= num2.length())
            return func(num1, num2);
        else
            return func(num2, num1);
    }
    private String func(String num1, String num2) {
        String res = new String("");
        for (int i = num2.length()-1; i >= 0; i--) {
            int n2 = num2.charAt(i)-'0';
            int carry = 0;
            StringBuilder sbTmp = new StringBuilder();
            if (i < num2.length()-1) {
                int iTmp = i;
                while (iTmp < num2.length()-1) {
                    sbTmp.append(0);
                    iTmp++;
                }
            }
            for (int j = num1.length()-1; j >= 0; j--) {
                int n1 = num1.charAt(j)-'0';
                int tmp = n1*n2+carry;
                carry = tmp/10;
                sbTmp.append(tmp%10);
            }
            if (carry > 0)
                sbTmp.append(carry);
            String resTmp = sbTmp.reverse().toString();
            res = plus(resTmp, res);
        }
        return res;
    }
    private String plus(String num1, String num2) {
        int n1 = 0, n2 = 0, carry = 0, tmp = 0;
        int i = num1.length()-1, j = num2.length()-1;
        StringBuilder res = new StringBuilder();
        while (i>=0 || j>=0) {
            n1 = i>=0 ? num1.charAt(i)-'0' : 0;
            n2 = j>=0 ? num2.charAt(j)-'0' : 0;
            tmp = n1+n2+carry;
            carry = tmp/10;
            res.append(tmp%10);
            i--;
            j--;
        }
        if (carry == 1)
            res.append(1);
        return res.reverse().toString();
    }
}
```

