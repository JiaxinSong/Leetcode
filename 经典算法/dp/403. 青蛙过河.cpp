/*
思路①、使用二维数组的动态规划
         动态规划
         dp[i][k] 表示能否由前面的某一个石头 j 通过跳 k 步到达当前这个石头 i ，这个 j 的范围是 [1, i - 1]
         当然，这个 k 步是 i 石头 和 j 石头之间的距离
         那么对于 j 石头来说，跳到 j 石头的上一个石头的步数就必须是这个 k - 1 || k || k + 1
         由此可得状态转移方程：dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1]
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        dp[0][0] = true;

        for (int i = 1; i < len; ++i) {
                if (stones[i] - stones[i-1] > i) return false;
                /*
                	为什么有这么个判断？
                	因为其他石头跳到第 i 个石头跳的步数 k 必定满足 k <= i
                	这又是为什么？
                	1、比如 nums = [0,1,3,5,6,8,12,17]
                	   那么第 0 个石头跳到第 1 个石头，步数肯定为 1，然后由于后续最大的步数是 k + 1，因此第 1 个石头最大只能跳 2 个单位
                 	   因此如果逐个往上加，那么第 2 3 4 5 ... 个石头最多依次跳跃的步数是 3 4 5 6...
                	2、 第 i 个石头能跳的最大的步数是 i + 1，那么就意味着其他石头 j 跳到第 i 个石头的最大步数只能是 i 或者 j + 1
                	   而 这个 k 是其他石头跳到 i 石头上来的，因此 k 必须 <= i （或者是 k <= j + 1）
                */
                for (int j = i-1; j >= 0; --j) {                // j从后往前， 方便剪枝
                        int k = stones[i] - stones[j];          // 直接计算可能的K值
                        if (k > j+1)    break;                  // 剪枝二: 如果下标j 不可能跳到下标i， 那么下标j之前的石头更加不可能可以跳到下标i的石头位置了，所以可以跳出该层循环
                        dp[i][k] = dp[j][k-1] || dp[j][k] || dp[j][k+1];
                }
        }
        return *(std::max_element(dp[len-1].begin(), dp[len-1].end()));
    }
};

