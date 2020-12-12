class Solution {
public:
    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)  //k + count < ans：比coins[c_index]小的不考虑
    {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.rbegin(),coins.rend());
    int ans = INT_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
}
};



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max= amount+1;
        vector<int> dp(amount+1,Max);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<(int)coins.size();++j){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount ? -1:dp[amount];
    }
};
