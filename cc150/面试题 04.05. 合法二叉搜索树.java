/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    //前一个结点，全局的
    TreeNode prev;
    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        //访问左子树
        if (!isValidBST(root.left))
            return false;
        //访问当前节点：如果当前节点小于等于中序遍历的前一个节点直接返回false。
        if (prev != null && prev.val >= root.val)
            return false;
        prev = root;
        //访问右子树
        if (!isValidBST(root.right))
            return false;
        return true;
    }

}

