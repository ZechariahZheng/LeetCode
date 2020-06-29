## LeetCode_56 合并空间

给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

**思路：将数组中的左侧元素进行排序，然后进行合并，合并原则**
**合并原则：a=[1,4]、b=[2,3]**
**1、当重叠后的区间**
**左边 == a[0]**
**右边 == Max(a[1], b[1])**

```java
class Solution {
        public int[][] merge(int[][] intervals) {
            quickSort(intervals, 0, intervals.length-1);
            ArrayList<int[]> resultTmp = new ArrayList<>();
            for (int i = 0; i < intervals.length; i++) {
                int n = resultTmp.size()-1;
                if (n>=0 && resultTmp.get(n)[1]>=intervals[i][0]) { //重叠区间
                    int[] ArrayTmp = resultTmp.get(n);
                    int left = ArrayTmp[0];
                    int right = Math.max(ArrayTmp[1], intervals[i][1]);
                    int[] tmp = new int[2];
                    tmp[0] = left;
                    tmp[1] = right;
                    resultTmp.remove(n);
                    resultTmp.add(tmp);
                } else if (i+1<intervals.length && intervals[i][1]>=intervals[i+1][0]) {	//重叠区间
                    int left = intervals[i][0];
                    int right = Math.max(intervals[i][1], intervals[i+1][1]);
                    int[] tmp = new int[2];
                    tmp[0] = left;
                    tmp[1] = right;
                    resultTmp.add(tmp);
                    i++;
                } else {	//不重叠
                    int[] tmp = new int[2];
                    tmp[0] = intervals[i][0];
                    tmp[1] = intervals[i][1];
                    resultTmp.add(tmp);
                    if (i == intervals.length-2) {
                        int[] tmp1 = new int[2];
                        tmp1[0] = intervals[i+1][0];
                        tmp1[1] = intervals[i+1][1];
                        resultTmp.add(tmp1);
                    }
                }
            }
            int[][] result = new int[resultTmp.size()][];
            for (int i = 0; i < resultTmp.size(); i++) {
                result[i] = new int[2];
                result[i][0] = resultTmp.get(i)[0];
                result[i][1] = resultTmp.get(i)[1];
            }
            return result;
        }

        //根据首个元素进行快速排序
        void quickSort(int[][] intervals, int l, int r) {
            if (l < r) {
                int i = l, j = r, x = intervals[i][0], y = intervals[i][1];
                while (i < j) {
                    while (i<j && intervals[j][0]>=x)
                        j--;
                    if (i < j) {
                        intervals[i][0] = intervals[j][0];
                        intervals[i][1] = intervals[j][1];
                        i++;
                    }
                    while (i<j && intervals[i][0]<x)
                        i++;
                    if (i < j) {
                        intervals[j][0] = intervals[i][0];
                        intervals[j][1] = intervals[i][1];
                        j--;
                    }
                }
                intervals[i][0] = x;
                intervals[i][1] = y;
                quickSort(intervals, l, i-1);
                quickSort(intervals, i+1, r);
            }
        }
    }
```

