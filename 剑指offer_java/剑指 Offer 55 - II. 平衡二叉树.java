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
    public boolean isBalanced(TreeNode root) {
        return recur(root)!=-1;
    }
    int recur(TreeNode root){
        if(root==null) return 0;
        int x=recur(root.left);
        if(x==-1) return -1;
        int y=recur(root.right);
        if(y==-1) return -1;
        return Math.abs(x-y)>=2? -1:Math.max(x,y)+1;

    }
}
