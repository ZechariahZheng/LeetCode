## LeetCode_54 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

思路：
1、设定上下左右边界
2、向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删除，体现在代码中就是重新定义上边界
3、判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
4、若上下边界不交错，则遍历还未结束，接着向下向左向上移动
5、不断循环以上步骤，直到某两边界交错，则跳出循环，返回答案

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> result = new ArrayList<>();
        if (matrix.length == 0)
            return result;
        //设定上下左右边界
        int up = 0;
        int down = matrix.length-1;
        int left = 0;
        int right = matrix[0].length-1;

        while (true) {
            //向右移动到最右
            for (int i = left; i <= right; i++) {
                result.add(matrix[up][i]);
            }
            up++;
            if (up > down) {
                break;
            }
            //向下移动
            for (int i = up; i <= down; i++) {
                result.add(matrix[i][right]);
            }
            right--;
            if (right < left) {
                break;
            }
            //向左移动
            for (int i = right; i >= left; i--) {
                result.add(matrix[down][i]);
            }
            down--;
            if (down < up) {
                break;
            }
            //向上移动
            for (int i = down; i >= up; i--) {
                result.add(matrix[i][left]);
            }
            left++;
            if (left > right) {
                break;
            }
        }

        return result;
    }
}
```

