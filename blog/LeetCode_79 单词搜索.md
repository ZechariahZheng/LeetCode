## LeetCode_79 单词搜索

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

**思路：先找到第一个相同的字符，找到之后利用深度搜索,同时设置标志位继续查找**

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        int col = board.length;
        int raw = board[0].length;

        //设置标志位
        boolean[][] flag = new boolean[col][raw];
        //找到第一个相同的字符
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < raw; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (dfs(board, flag, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //深度搜索
    private boolean dfs(char[][] board, boolean[][] flag, int row, int col, int pos, String word) {
        if (pos >= word.length())
            return true;
        if (row>=board.length || col>=board[0].length || row<0 || col<0)
            return false;
        if (flag[row][col] || board[row][col]!=word.charAt(pos)) {
            return false;
        } else {
            flag[row][col] = true;
            pos++;
            if (dfs(board, flag, row+1, col, pos, word) ||
                    dfs(board, flag, row-1, col, pos, word) ||
                    dfs(board, flag, row, col+1, pos, word) ||
                    dfs(board, flag, row, col-1, pos, word))
                return true;
            flag[row][col] = false;
            return false;
        }
    }
}
```

