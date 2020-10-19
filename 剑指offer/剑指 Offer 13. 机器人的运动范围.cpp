//回溯法

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        vector<vector<bool>> valid(m,vector<bool>(n,true));
        return dfs(valid,m,n,0,0,k);
    }

    int dfs(vector<vector<bool>>& valid,int m,int n, int row , int col,int k){
        int sum=getSum(row)+getSum(col);
        if(row>=m||col>=n||sum>k||!valid[row][col]) return 0;
        valid[row][col]=false;
        return 1+dfs(valid,m,n,row+1,col,k)+dfs(valid,m,n,row,col+1,k);
    }

    int getSum(int x){
        int sum=0;
        for(;x>0;x/=10){
            sum+=x%10;
        }
        return sum;
    }
    
};
