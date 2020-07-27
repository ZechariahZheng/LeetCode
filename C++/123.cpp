#include <vector>
#include <memory.h>

using namespace std;

/*买卖股票的最佳时机 III
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
              max(   选择 rest  ,             选择 sell      )

解释：今天我没有持有股票，有两种可能：
要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
              max(   选择 rest  ,           选择 buy         )

解释：今天我持有着股票，有两种可能：
要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size(); 
        int max_k = 2;
        int dp[n][max_k+1][2]; 
        memset(dp, 0, sizeof(dp));

        for(int i=0; i < n; i++) { 
    
            for(int k=1; k <= max_k; ++k) { 
                
                if(i==0) { 
                    dp[0][k][0] =0;
                    dp[0][k][1] =-prices[0];
                    continue;
                }

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]   + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
               
            }
        }
        return dp[n-1][max_k][0];
    }
};