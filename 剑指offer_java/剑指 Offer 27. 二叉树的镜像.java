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
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null) return null;
        TreeNode x= root.right;
        root.right=root.left;
        root.left=x;
        mirrorTree(root.left);
        mirrorTree(root.right);
        return root;
    }
}
