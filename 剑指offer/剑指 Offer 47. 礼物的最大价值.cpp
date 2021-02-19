class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
      
       int r=grid.size(),c=grid[0].size();
       vector<int> dp(c+1,0);
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               dp[j+1]=max(dp[j],dp[j+1])+grid[i][j];
           }
       }
       return dp[c];
    
    }
    
};
