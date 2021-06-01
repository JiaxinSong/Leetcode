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
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return gudge(root.left,root.right);
    }
    boolean gudge(TreeNode a, TreeNode b){
        if(a==null && b==null) return true;
        if(a== null) return false;
        if(b==null)   return false;
        if(a.val!= b.val) return false;
        return gudge(a.right,b.left)&& gudge(a.left,b.right);
    }
}
