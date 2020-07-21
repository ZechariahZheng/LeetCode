#include <vector>

using namespace std;

/*三角形最小路径和
定义dp[i][j]为到达i，j这个位置的最小路径和
状态转义方程为dp[i][j] = min{dp[i-1][j-1], dp[i-1][j]}+triangle[i][j]
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        //初始化
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            //每一行最左侧的元素
            dp[i][0] = dp[i-1][0]+triangle[i][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
            }
            //每一行最右侧的元素
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};