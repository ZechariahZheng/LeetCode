#include <vector>
#include <memory.h>

using namespace std;

/*买卖股票的最佳时机 II
思路：动态规划
dp[i][j]:其中i表示第i天，
         j=0表示第i天持有股票，j=1表示第i天持有现金
第一天不买入：dp[0][0] = 0
第一天买入：dp[0][0] = -prices[0]   
状态转移方程
dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0]);
dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        memset(dp, 0, n*2);
        
        dp[0][0] = 0-prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};