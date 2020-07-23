from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0; minPrices = 99999
        for i in range(len(prices)):
            res = max(res, prices[i]-minPrices)
            minPrices = min(minPrices, prices[i])
        return res