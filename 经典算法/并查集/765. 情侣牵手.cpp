//并查集  https://zhuanlan.zhihu.com/p/93647900/

//  https://leetcode-cn.com/problems/couples-holding-hands/solution/cbing-cha-ji-best-100wo-hen-a-by-feng-zi-iw0m/

/*
定义多个交织在一起的情侣为“一堆”。比如，有正常的4对情侣：
0 1 2 3 4 5 6 7 
下面这种情况，只有 6 7 是正常在一起的情侣，其它三对情侣交织在一起，叫“一堆”
0 2 1 4 3 5 ｜ 6 7
下面这种情况，没有正常的的情侣，俩俩交织在一起，有2个“一堆”情侣
0 2 1 3 ｜ 4 6 7 5

找出数组里面有多少个“一堆”情侣，找出数组里面有多少个“一堆”情侣，找出数组里面有多少个“一堆”情侣。把每个“一堆”情侣最少交换次数加起来就可以了。

而计算“一堆”最好的办法就是使用并查集。直接套用并查集代码就可以。

累加最少交换次数：
(n1 - 1) + (n2 - 1) + .....
每个“一堆”都需要 - 1，累加起来就是有几个“一堆”的总数；n1 + n2 + ... 也就是总情侣的个数；那么最少交换次数的公式就：
情侣总数 - “一堆”情侣总数，使用了并查集，也就是情侣总数 - 并查集个数
*/

class UnionFind {
private:
    vector<int> parent;
    int counts;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i)
            parent.push_back(i);
        counts = n;
    }

    int find(int p) {
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    void merge(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ, --counts;
    }

    int getCount(void) {return counts;}
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        UnionFind uf(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2)
            uf.merge(row[i] / 2, row[i + 1] / 2);
        // 情侣总数 - 并查集个数
        return row.size() / 2 - uf.getCount();
    }
};
