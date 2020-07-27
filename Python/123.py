from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        max_k = 2
        dp = [[[0 for i in range(2)] for j in range(max_k+1)] for k in range(n)]
        
        for i in range(n):
            for j in range(1, max_k+1):
                if i == 0:
                    dp[0][j][0] = 0
                    dp[0][j][1] = -prices[0]
                    continue
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]   + prices[i])
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        return dp[n-1][max_k][0]
