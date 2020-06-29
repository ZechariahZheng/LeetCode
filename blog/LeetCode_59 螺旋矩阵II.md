## LeetCode_59 螺旋矩阵II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

思路：顺时针打印矩阵的思路，只不过由以前的输出，变为了输入

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[] tmp = func(n);
        int[][] matrix = new int[n][n];
        int up = 0, down = n-1, left = 0, right = n-1;
        int index = 0;
        //开始输入
        while (true) {
            for (int i = left; i <= right; i++)
                matrix[up][i] = tmp[index++];
            up++;
            if (up > down)
                break;
            for (int i = up; i <= down; i++)
                matrix[i][right] = tmp[index++];
            right--;
            if (right < left)
                break;
            for (int i = right; i >= left; i--)
                matrix[down][i] = tmp[index++];
            down--;
            if (down < up)
                break;
            for (int i = down; i >= up; i--)
                matrix[i][left] = tmp[index++];
            left++;
            if (left > right)
                break;
        }
        return matrix;
    }
    
    private int[] func(int n) {
        long tmp = n*n;
        int[] result = new int[tmp];
        for (int i = 0; i < tmp; i++) {
            result[i] = tmp;
        }
        return result;
    }
}
```

