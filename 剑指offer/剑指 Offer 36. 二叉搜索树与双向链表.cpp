class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        // vector中安装中序遍历顺序保存了所有的node
        vector<Node*> nodes;

        inorderTraverse(root, nodes);

        int n = nodes.size();
        for (int i = 0; i < n; i++) {
            // (i + n - 1) % n 避免第一个结点的index 0 减1出现负数
            nodes[i]->left = nodes[(i + n - 1) % n];
            // (i + 1) % n 是为了避免最后一个结点 + 1越界
            nodes[i]->right = nodes[(i + 1) % n];
        }
        return nodes[0];
    }

    void inorderTraverse(Node *root, vector<Node *> &nodes) {
        if (root == NULL)
            return;
        inorderTraverse(root->left, nodes);
        nodes.push_back(root);
        inorderTraverse(root->right, nodes);
    }
};
