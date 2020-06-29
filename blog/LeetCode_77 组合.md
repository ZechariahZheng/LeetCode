## LeetCode_77 组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

思路：和全排列问题一样，这是一道使用回溯算法解决的经典问题。**而分析回溯问题，我们常常需要画图来帮助我们理清思路和寻找边界条件**。

![](E:\文档\blog\pic\组合.png)

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        if (n<=0 || k<=0 || k>n)
            return result;
        func(new ArrayList<Integer>(), result, 1, n, k);
        return result;
    }
    
    private void func(List<Integer> path, List<List<Integer>> result, int tmp, int n, int k) {
        if (path.size() == k) {
            List<Integer> pathTmp = new ArrayList<>(path);
            result.add(pathTmp);
            return;
        }
        for (int i = tmp; i <= n-(k-path.size())+1; i++) {
            path.add(i);
            func(path, result, i+1, n, k);
            path.remove(path.size()-1);
        }
    }
}
```

