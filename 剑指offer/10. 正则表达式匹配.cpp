// 由于 if(p[0] == '*') return false; 排除了星号前面没有其他字符  所以几j==1时dp[i][j - 2]不会发生

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0){   // 边界特判
            if(n == 0) return true;
            else return false;
        }
        if(p[0] == '*') return false;  // 星号前面没有其他字符是非法的状态
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        s = " " + s;
        p = " " + p;
        for(int i = 2; i <= m; i ++){  // 处理0的情况。也就p和空字符串匹配的情况
            if(p[i] == '*') dp[0][i] = dp[0][i - 2];
            else dp[0][i] = false;
        }
        for(int i = 1; i <= n; i ++){  // 开始进行状态转移
            for(int j = 1; j <= m; j ++){
                if(p[j] != '*') dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '.');  // 不是星号
                else{   
                    dp[i][j] = dp[i][j - 2] || dp[i-1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');  // 是星号
                }
            }
        }
        return dp[n][m];
    }
};
