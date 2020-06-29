## LeetCode_74 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true

**思路：利用矩阵升序的特性，选择右上角或者左下角作为切入点， 算法复杂度为O(m+n) m 为matrix行数 n 为matrix列数 **

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0)
            return false;
        int row = 0, col = matrix[0].length-1;
        while (row<matrix.length && col>=0) {
            if (matrix[row][col] < target)
                row++;
            else if (matrix[row][col] > target)
                col--;
            else
                return true;
        }
        return false;
    }
}
```

