若 p 或 q 的值等于 root 的值，说明 p 或 q 为 root，即最近公共祖先。
若 p 和 q 分居 root 两侧，说明 root 为最近公共祖先。
若 p 和 q 都在 root 左边，则向左寻找最近公共祖先。
若 p 和 q 都在 root 右边，则向右寻找最近公共祖先
先放C++代码，思路简单易懂。

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p,q);
        }
        while(root){
        if(p->val<=root->val&&q->val>=root->val){
            return root;
        }
        else if(p->val<root->val&&q->val<root->val){
            root=root->left;
        }
        else root= root->right;

        }
        return root;



    }

};
