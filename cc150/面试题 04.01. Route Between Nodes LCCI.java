class Solution {
    boolean[] visited=null;
    public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
        List<List<Integer>> edges=new ArrayList<>();
        for(int i=0;i<n;i++){
            edges.add(new ArrayList<>());
        }
        for(int i=0;i<graph.length;i++){
            edges.get(graph[i][0]).add(graph[i][1]);
        }
        visited=new boolean[n];
        return dfs(edges,start,target);
    }
    public boolean dfs(List<List<Integer>> edges, int start,int target){
        List<Integer> list=edges.get(start);
        if(list.contains(target)) return true;
        else if(!visited[start]){
            visited[start]=true;
            for(int cur:list){
                if(dfs(edges,cur,target)) return true;
            }
        }
        return false;
    }
}




class Solution {
    // 访问状态数组
    private boolean[] visited = null;
    public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
        // 创建访问状态数组
        this.visited = new boolean[graph.length];
        // DFS
        return helper(graph, start, target);
    }

    private boolean helper(int[][] graph, int start, int target) {
        // 深度优先搜索
        for (int i = 0; i < graph.length; ++i) {
            // 确保当前路径未被访问（该判断主要是为了防止图中自环出现死循环的情况）
            if (!visited[i]) {
                // 若当前路径起点与终点相符，则直接返回结果
                if (graph[i][0] == start && graph[i][1] == target) {
                    return true;
                }
                if (graph[i][1] == target ) {
                    visited[i]=true;
                    if(helper(graph,start,graph[i][0])) return true;
                }
                
            }
        }
        return false;
    }
}
