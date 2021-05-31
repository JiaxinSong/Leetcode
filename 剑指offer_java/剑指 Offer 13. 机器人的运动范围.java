class Solution {
    boolean [][]memory;
    int res=0;
    public int movingCount(int m, int n, int k) {
        if(k==0|| m==1&& n==1) return 1;
        memory=new boolean[m][n];
        dfs(0,0,k,m,n);
        return res;
    }
    void dfs(int x,int y,int k,int m,int n){
        if(x==m||y==n||memory[x][y]) return;
        if(gudge(x)+gudge(y)>k) return;
        memory[x][y]=true;
        res++;
        dfs(x+1,y,k,m,n);
        dfs(x,y+1,k,m,n);
    }
    int gudge(int x){
        if(x==100) return 1;
        return x/10+x%10;
    }
}
