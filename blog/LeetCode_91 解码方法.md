## LeetCode_91 解码方法

一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

思路：

- **0不能单独解码** 
-  **两位数必须在1与26之间。**

**这道题目实际上是用DP去做，仔细想的话，可以发现就是约束版的f(n) = f(n-1) + f(n-2);，其中如果是s[n-1]为0，f(n-1) = 0，f(n) = f(n-2)，因为0无法单独解码，而f(n-2)的条件则是必须在1与26之间，否则f(n) = f(n-1)。** 

```java
class Solution {
    public int numDecodings(String s) {
        int cnt = 0;
        if (s.length()==0 || (s.length()==1&&s.charAt(0)=='0'))
            return 0;
        if (s.length() == 1)
            return 1;
        int[] dp = new int[s.length()+1];
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            dp[i+1] = s.charAt(i)=='0' ? 0 : dp[i];
            if (i>0 && (s.charAt(i-1)=='1'||(s.charAt(i-1)=='2'&&s.charAt(i)<='6')))
                dp[i+1] += dp[i-1];
        }
        return dp[s.length()];
    }
}
```

