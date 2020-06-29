## LeetCode_60 第k个排列

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"



**思路：（回溯法+剪枝）全排列，按照顺序来便是排序好的，同时达到每个支路的节点，检查是否满足要求。**

```java
class Solution {
    private Integer tmp = 0;

        public String getPermutation(int n, int k) {
            boolean[] visited = new boolean[n];
            ArrayList<String> result = new ArrayList<>();
            result.add("");
            func(n, visited, k, new Stack<Integer>(), result);
            return result.get(result.size()-1);
        }

        public void func(int n, boolean[] visited, Integer target, Stack<Integer> path, ArrayList<String> result) {
            if (!result.get(result.size()-1).equals(""))
                return;
            if (path.size() == n) {
                tmp++;
                if (tmp.equals(target)) {
                    StringBuilder sb = new StringBuilder();
                    while (!path.empty()) {
                        sb.append(path.pop());
                    }
                    result.add(sb.reverse().toString());
                    return;
                }
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    path.push(i+1);
                    visited[i] = true;
                    func(n, visited, target, path, result);
                    if (!path.empty())
                        path.pop();
                    visited[i] = false;
                }
            }
        }
}
```

