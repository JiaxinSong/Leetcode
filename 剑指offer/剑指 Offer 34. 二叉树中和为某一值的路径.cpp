//注意回溯法的顺序 不能在return时插入 因为左右两个几点会插入两次



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int> > res;
    vector<int> temp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        recursion(root, sum);
        return res;
    }
    void recursion(TreeNode *root, int sum)
    {
        if(!root) return;
        temp.push_back(root -> val);
        sum -= root -> val;
        if(sum == 0 && !root -> left && !root -> right)
            res.push_back(temp);
        recursion(root -> left, sum); // 左
        recursion(root -> right, sum); // 右
        temp.pop_back(); // 函数退出之前先弹出当前节点
    }
};
