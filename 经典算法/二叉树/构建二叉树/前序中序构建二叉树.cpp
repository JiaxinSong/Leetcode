class Solution {
private:
    unordered_map<int, int> findIndex;
    int index = 0;      
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) 
            findIndex[inorder[i]] = i;  //建立数组值到索引的映射
        return build(preorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int start, int end){        
        if(start > end) return NULL;    // 中序的start和end
        int i = findIndex[preorder[index]];
        TreeNode *tree = new TreeNode(preorder[index++]);
        tree->left  = build(preorder, start, i - 1); 
        tree->right = build(preorder, i + 1, end);   
        return tree;
    }
};
