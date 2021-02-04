class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        swap(node->left,node->right);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
    }
};



class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)   return NULL; 
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        
        return root;        
    }
};
