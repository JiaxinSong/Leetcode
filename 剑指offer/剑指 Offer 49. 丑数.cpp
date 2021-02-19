//注意if去重  不是if else

class Solution {
public:
    int nthUglyNumber(int n) {
        int a=0,b=0,c=0;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            dp[i]=min(2*dp[a],min(3*dp[b],5*dp[c]));
            if(2*dp[a]==dp[i]) a++;
            if(3*dp[b]==dp[i]) b++;
            if(5*dp[c]==dp[i]) c++;
        }
        return dp[n-1];
    }
};
