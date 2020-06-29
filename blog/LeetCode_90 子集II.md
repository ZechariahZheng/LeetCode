## LeetCode_90 子集II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

**思路：回溯法+剪枝；遇到相同的数字跳过即可**

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<Integer>());
        if (nums.length == 0)
            return result;
        Arrays.sort(nums);
        boolean[] flag = new boolean[nums.length];
        func(nums, 0, flag, new ArrayList<>(), result);
        return result;
    }

    public void func(int[] nums, int start, boolean[] flag, List<Integer> path, List<List<Integer>> result) {
        if (path.size() != 0) {
            List<Integer> tmp = new ArrayList<>(path);
            result.add(tmp);
        }
        for (int i = start; i < nums.length; i++) {
            if (i!=start && nums[i-1]==nums[i]) {
                continue;
            } else if (!flag[i]) {
                path.add(nums[i]);
                flag[i] = true;
                func(nums, i+1, flag, path, result);
                flag[i] = false;
                path.remove(path.size()-1);
            }
        }
    }
}
```

