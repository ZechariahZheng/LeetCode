## LeetCode_62 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

**思路：**
**dp[i][j]到达i,j最多路径 动态方程：dp[i][j] = dp[i-1][j]+dp[i][j-1]**
**注：**
**对于第一行dp[0][j]，或者第一列dp[i][0]，由于都是在边界，所以只能为1**

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i==0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j]+dp[i]+dp[j-1];
            }
        }
        return dp[m-1][n-1];
    }
}
```

