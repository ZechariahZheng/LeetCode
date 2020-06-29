## LeetCode_73 矩阵置零

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

**思路：保存下要移除的行和列，然后全部将其置零**

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> row = new HashSet<>();
        Set<Integer> col = new HashSet<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    row.add(i);
                    col.add(j);
                }
            }
        }
        for (Integer tmp: row) {
            for (int i = 0; i < matrix[0].length; i++) {
                matrix[tmp][i] = 0;
            }
        }
        for (Integer tmp: col) {
            for (int i = 0; i < matrix.length; i++) {
                matrix[i][tmp] = 0;
            }
        }
    }
}
```

**改进算法：**

**1、遍历整个矩阵，如果 cell[i][j] == 0 就将第 i 行和第 j 列的第一个元素标记。**
**2、第一行和第一列的标记是相同的，都是 cell[0][0]，所以需要一个额外的变量告知第一列是否被标记，同时用 cell[0][0] 继续表示第一行的标记。**
**3、然后，从第二行第二列的元素开始遍历，如果第 r 行或者第 c 列被标记了，那么就将 cell[r][c] 设为 0。这里第一行和第一列的作用就相当于方法一中的 row_set 和 column_set 。**
**4、然后我们检查是否 cell[0][0] == 0 ，如果是则赋值第一行的元素为零。**
**5、然后检查第一列是否被标记，如果是则赋值第一列的元素为零。**



