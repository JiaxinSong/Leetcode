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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A==null || B==null) return false;
        return isSubStructure(A.left,B)||isSubStructure(A.right,B)||isSub(A,B);
    }
    boolean isSub(TreeNode A, TreeNode B){
        if(B==null) return true;
        if(A==null|| A.val!=B.val) return false;
        return isSub(A.left,B.left)&&isSub(A.right,B.right);
    }

}
