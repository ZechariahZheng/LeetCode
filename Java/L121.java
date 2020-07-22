public class L121 {
    public int maxProfit(int[] prices) {
        int res = 0;
        int minPrices = 999999;

        for (int i = 0; i < prices.length; i++) {
            res = Math.max(res, prices[i]-minPrices);
            minPrices = Math.min(minPrices, prices[i]);
        }
        return res;
    }
}