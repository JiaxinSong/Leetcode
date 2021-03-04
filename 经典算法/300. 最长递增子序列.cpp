//O n2


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};



// O nlogn

//我们维护一个数组 d[i]d[i] ，表示长度为 ii 的最长上升子序列的末尾元素的最小值
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> minnums;
        for(int v : nums)
        {
            auto pos = lower_bound(minnums.begin(), minnums.end(), v);
            if(pos == minnums.end()) {
                minnums.push_back(v);
            } else {
                *pos = v;
            }
        }
        return minnums.size();
    }
};

