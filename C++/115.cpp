#include <string>
#include <unordered_map>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

/*不同的子序列
状态表示：dp[i][j]表示d的前i个字符的子序列能组成t的前j个字符的方法数。
则最终结果应该为：dp[s.size()][t.size()]
状态转移：
对于dp[i][j]中s[i-1]和t[j-1]有两种情况：

s[i-1] == t[j-1]时，相等时，对于s[i-1]有两种处理方法:
(1)、将s[i-1]看作子序列的最后一个字符的情况下，其方法数等于s的前i-1能构成t的前j-1个的方法数dp[i-1][j-1]
(2)、不考虑s[i-1]时，剩余的s的前i-1个能构成t的前j个的方法数：dp[i-1][j]
最终的方法数为两者相加：dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
s[i-1] != t[j-1]时，此时的方法数等价于移除s的第i个元素后，剩余的前i-1个元素的子序列能构成t的前j个元素的方法数：dp[i][j] = dp[i-1][j]

*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (m == 0)
            return 1;
        if (n == 0)
            return 0;
        vector<vector<long>> dp(n+1, vector<int>());
        for (int i= 0; i <= n; i++) {
            dp[i].resize(m+1);
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("b", "a") << endl;
    return 0;
}