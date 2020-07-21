from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = [[0 for i in range(n)] for j in range(n)]
        dp[0][0] = triangle[0][0]
        
        for i in range(1, n):
            dp[i][0] = dp[i-1][0] + triangle[i][0]
            for j in range(1, i):
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
            dp[i][i] = dp[i-1][i-1] + triangle[i][i]
        return min(dp[n-1])
