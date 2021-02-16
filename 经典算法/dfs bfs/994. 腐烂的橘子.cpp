//dfs java
class Solution {
private int[][] temp ;

public int orangesRotting(int[][] grid) {
	if (grid.length == 0) {
        return -1;
	}
	temp = grid;
	int count=0;
    for(int i=0;i<grid.length;i++) {
    	for(int j=0;j<grid[i].length;j++) {
    		if(grid[i][j]==2) {
    			dfs(i,j,2);
    		}
    		 if(grid[i][j]==0){
                 count++;
             }
    	}
    }
  if(count==(grid.length*grid[0].length)) {
	  return 0;
  }
    int sum = 0;
    for(int i=0;i<temp.length;i++) {
    	for(int j =0;j<temp[0].length;j++) {
    		if(temp[i][j]==1) {
    			return -1;
    		}
    		sum = Math.max(sum, temp[i][j]);
    	}
    }
    return sum-2;
}

private void dfs(int i, int j, int value) {
	// TODO Auto-generated method stub
	temp[i][j]=value;
	if(i>0&&(temp[i-1][j]==1||temp[i-1][j]-temp[i][j]>1)) {
		dfs(i-1,j,value+1);
	}
	if(j>0&&(temp[i][j-1]==1||temp[i][j-1]-temp[i][j]>1)) {
		dfs(i,j-1,value+1);
	}
	if(i+1<=temp.length-1&&(temp[i+1][j]==1||temp[i+1][j]-temp[i][j]>1)) {
		dfs(i+1,j,value+1);
	}
	if(j+1<=temp[0].length-1&&(temp[i][j+1]==1||temp[i][j+1]-temp[i][j]>1)) {
		dfs(i,j+1,value+1);
	}
	
}
}


//bfs
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
        }
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        while(!q.empty()) {
            int n = q.size();
            bool rotten = false;
            for(int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                for(auto cur: dirs) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;
        } 
        return fresh ? -1 : min;
    }
};


