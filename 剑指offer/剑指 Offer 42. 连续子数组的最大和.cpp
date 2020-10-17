// dp>=0 是连续条件 一旦 dp<0就要另起炉灶
//同时对于dp[i]=max(dp[i-1]+nums[i],nums[i]),两种情况都加了nums[i]，只是前面多加了dp[i-1]，所有很容易推出，当dp[i-1]<0时，后者大，反之前者大



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp=nums[0];
        int Max =nums[0];
        for(int i=1;i<n;i++){
            if(dp>=0){
                dp+=nums[i];
            }
            else{
                dp=nums[i];
            }
            Max= max(Max,dp);

        }
        return Max;
    }
};
