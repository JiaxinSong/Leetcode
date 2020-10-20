
//动态规划 
//n个骰子投到 m的次数是 n-1个骰子投到 m-6到m-1 的和
//j - cur < i-1因为 i-1个骰子的和最小是i-1
//if(j-cur>(i-1)*6) continue;  最大值是 (i-1)*6

class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[12][67];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = i; j <= 6*i; j ++) {
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur < i-1) {
                        break;
                    }
                    if(j-cur>(i-1)*6) continue;
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[n][i] * 1.0 / all);
        }
        return ret;
    }
};












//空间优化 实际没有效果

class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = 6*i; j >= i; j --) {
                dp[j] = 0;
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur < i-1) {
                        break;
                    }
                    if(j-cur>(i-1)*6) continue;
                    dp[j] += dp[j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[i] * 1.0 / all);
        }
        return ret;
    }
};
