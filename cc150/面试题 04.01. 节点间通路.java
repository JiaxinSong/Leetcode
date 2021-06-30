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
