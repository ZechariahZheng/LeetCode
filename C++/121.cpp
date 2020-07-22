#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrices = INT_MAX;
        for (auto prices: prices) {
            res = max(res, prices-minPrices);
            minPrices = min(minPrices, prices);
        }
        return res;
    }
};