// 所以，我们要找到每一个 node 的距离为 1, 2, 4, 8, 16, 32, ... 的祖先，直到达到树的最大的高度。树的最大的高度是 logn 级别的。

// 这样做，状态总数是 O(nlogn)，可以使用 O(nlogn) 的时间做预处理。

// 之后，根据预处理的结果，可以在 O(logn) 的时间里完成每次查询：对于每一个查询 k，把 k 拆解成二进制表示，然后根据二进制表示中 1 的位置，累计向上查询。




public class TreeAncestor {
    private int[][] ST;
    private int maxIteration ;

    public TreeAncestor(int n, int[] parent) {
        this.maxIteration = 32 - Integer.numberOfLeadingZeros(n - 1);
        ST = new int[n][maxIteration];
        for (int i = 0; i < n; ++i){
            ST[i][0] = parent[i];
        }
        for (int i = 0; i < n; ++i){
            for (int j = 1; j < maxIteration; ++j){
                ST[i][j] = ST[i][j - 1] == -1 ? -1 : ST[ST[i][j - 1]][j - 1];
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        if (node == -1 || k == 0){
            return node;
        }
        int highestBit = Integer.highestOneBit(k);
        int power = Integer.numberOfTrailingZeros(highestBit);
        if(power >= maxIteration){
            return -1;
        }
        return getKthAncestor(ST[node][power], k & (~highestBit));
    }
}
