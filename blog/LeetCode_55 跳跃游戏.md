## LeetCode_55 跳跃游戏

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

**思路：如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。如果可以一直跳到最后，就成功了。**

```java
class Solution {
    public boolean canJump(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length-1; i++) {
            if (i > max)
                return false;
            //能跳的最远距离
            max = Math.max(max, i+nums[i]);
        }
        return max>=nums.length-1 ? true : false;
    }
}
```

宽度搜索超时

```java
宽度搜索
class Solution {
    public boolean canJump(int[] nums) {
        dfs(nums, 0);
    }
	private boolean dfs(int[] nums, int index) {
		if (index == nums.length-1)
			return true;

		for (int i = 1; i < nums[index]; i++) {
			if (dfs(nums, index+i))
				return true;
		}
		return false;
	}
}
```

