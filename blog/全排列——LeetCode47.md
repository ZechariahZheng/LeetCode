全排列——LeetCode47

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

![image-20191128094004572](C:\Users\ZZS\AppData\Roaming\Typora\typora-user-images\image-20191128094004572.png)

思路：将序列进行排序之后，使用回溯+剪枝，对入栈的数字中：与前一个数字相等，并且前一个数字未被使用的跳过。

```java
//回溯法，先将数组进行排序
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
		List<List<Integer>> result = new ArrayList<>();
		if (nums.length == 0)
			return result;
        Arrays.sort(nums);
		boolean[] flag = new boolean[nums.length];
		func(result, new Stack<Integer>(), flag, 0, nums);
		
		return result;
    }
	
	public void func(List<List<Integer>> result, Stack<Integer> tmp, boolean[] flag, int index, int[] nums) {
		if (tmp.size() == nums.length) {
			result.add(new List<Integer>(tmp));
			return;
		}
		for (int i = index; i < nums.length; i++) {
			if (i!=0 && nums[i]==nums[i-1] && !flag[i-1]) {
				flag[i] = true;
				continue;
			}
			if (!flag[i]) {
				tmp.push(nums[i]);
				flag[i] = true;
				func(result, tmp, flag, i, nums);
				flag[i] = false;
				tmp.pop();
			}
		}
	}
}
```

