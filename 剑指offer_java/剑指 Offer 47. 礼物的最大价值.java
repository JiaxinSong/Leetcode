class Solution {
    public int maxValue(int[][] grid) {
        int a=grid.length,b=grid[0].length;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i==0&&j==0) continue;
                if(i==0) grid[i][j]+=grid[i][j-1];
                else if(j==0) grid[i][j]+=grid[i-1][j];
                else grid[i][j]+=Math.max(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[a-1][b-1];
        
    }
}
