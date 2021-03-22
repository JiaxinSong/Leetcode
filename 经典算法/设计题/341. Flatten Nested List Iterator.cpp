/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> res;
    int cnt = 0;                                                //cnt表示当前元素的指针

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    void dfs(vector<NestedInteger> &nestedList)
    {
        for (auto t : nestedList)
            if (t.isInteger()) res.push_back(t.getInteger());   //是整数就直接push
            else dfs(t.getList());                              //是数组就把数组拿出来继续递归
    }

    int next() {
        return res[cnt ++ ];                                    //不断指向下一个元素
    }
    
    bool hasNext() {
        return cnt < res.size();                                //判断当前指针位置是否超出边界
    }
};



/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
