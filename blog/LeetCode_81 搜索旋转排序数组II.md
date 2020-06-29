## LeetCode_81 搜索旋转排序数组II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false

**思路：二分查找，二分查找的本质就是不断地改变left或right的值，最终让其范围确定在搜寻的范围内。在本题之中，有旋转部分和有序部分**

```angelscript
//每次二分，左半部分和右半部分至少有一边是有序的，以此为条件可以分成两种情况：
//1、左半边是有序的
//(1) target落在左半边
//(2) otherwise
//2、右半边是有序的
//(1) target落在右半边
//(2) otherwise
//综上所述，一共两种可能性，这两种情况各自又有两种可能性，代码如下：
```

```java
class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;

        //左闭右闭
        while (left<=right) {
            //处理重复数字
            while (left<right && nums[left]==nums[left+1]) left++;
            while (left<right && nums[right]==nums[right-1]) right--;
            int mid = (left+right)/2;
            if (nums[mid] == target)
                return true;
            //左半部分有序
            if (nums[mid] >= nums[left]) {
                if (target<nums[mid] && target>=nums[left])
                    right = mid-1;      //targe落在左半边
                else
                    left = mid+1;       //target落在右半边
            } else {    //右半部分有序
                if (target>nums[mid] && target<=nums[right])
                    left = mid+1;       //target落在右半边
                else
                    right = mid-1;
            }
        }
        return false;
    }
}
```

