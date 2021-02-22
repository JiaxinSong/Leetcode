class Solution {
public:
int longestPalindromeSubseq(string s, vector<vector<int>>&f, int m) {
    int n = s.size();
    int ret = 0;
    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
                if ( i < m && j >=m){
                    ret = max(f[i][j] , ret);
                }
            } else {
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
    }
    return ret;
}

int longestPalindrome(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    string total = word1 + word2;
    vector<vector<int>> dp(m+n, vector<int>(m+n));
    return longestPalindromeSubseq(total, dp, m);
}
};

