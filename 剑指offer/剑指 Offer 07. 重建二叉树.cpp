//前中

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

//中后

class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        // 根据 root 所在位置分成左右两棵子树
        int index = idx_map[root_val];
        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;
        // 建立（元素，下标）键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};
