// 动态规划
// + 1. 创建一个二维数组 dp[len][len]
// + 2. dp[i][j]: i~j 组成的字数组 亚历克斯能够赢得的分数
// + 3. dp[i][j]: 这是有2个选择: 求出最大值
// 1: 亚历克斯拿走左边的i, 剩下dp[i+1][j] 就是李能够获取的最大分数, = piles[i] - dp[i+1][j]
// 2: 亚历克斯拿走右边的j, 剩下dp[i][j-1] 就是李能够获取的最大分数, = piles[j] - dp[i][j-1]
// + 4. 特例dp[i][i] 意味着只有一堆，那么肯定赢，= piles[i]

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int length = piles.size();
        auto dp = vector<vector<int>>(length, vector<int>(length));
        for (int i = 0; i < length; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] > 0;
    }
};

