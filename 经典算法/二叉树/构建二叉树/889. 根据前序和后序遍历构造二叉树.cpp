class Solution {
public:
    TreeNode* constructFromPrePost2(vector<int>& pre, int prel, int prer, vector<int>& post, int postl, int postr) {
        if(prel > prer)
            return NULL;
        else if(prel == prer)
            return new TreeNode(pre[prel]);
        TreeNode* node = new TreeNode(pre[prel]);
        for(int i = postl; i<=postr; i++){
            if(post[i] == pre[prel+1]) {
                node->left = constructFromPrePost2(pre, prel+1, prel+1+(i-postl), post, postl, i);
                node->right = constructFromPrePost2(pre, prel+2+(i-postl), prer, post, i+1, postr-1);
            }
        }
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost2(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
};
