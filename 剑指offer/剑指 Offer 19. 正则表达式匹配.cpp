//四种情况：
//1.匹配 2.以*结尾倒数第二个不匹配 3.以*结尾倒数第二个匹配 4.不匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool> > dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[0][0] = true;
        for(int i=2; i<=pLen; ++i)
        {
            if(p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2]; // 判断初始匹配位置
        }
        
        for(int i=1; i<=sLen; ++i)
        {
            for(int j=1; j<=pLen; ++j)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                {
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else 
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j]; 
                }
                else dp[i][j] = false;
            }
        }
        return dp[sLen][pLen];
    }
};
