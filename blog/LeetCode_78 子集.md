## LeetCode_78 子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

**思路：同77题相似，使用深度搜索**

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<Integer>());
        if (nums.length<=0)
            return result;
        for (int i = 1; i <= nums.length; i++) {
            dfs(nums, i, 0, new ArrayList<>(), result);
        }
        return result;
    }

    private void dfs(int[] nums, int n, int start, List<Integer>path, List<List<Integer>> result) {
        if (path.size() == n) {
            List<Integer> tmp = new ArrayList<>(path);
            result.add(tmp);
            return;
        }
        for (int i = start; i < nums.length; i++) {
            path.add(nums[i]);
            dfs(nums, n, i+1, path, result);
            path.remove(path.size()-1);
        }
    }
}
```

