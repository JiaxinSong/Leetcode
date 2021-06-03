/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> list = new ArrayList<>(); 
    public List<List<Integer>> pathSum(TreeNode root, int target) {
        if(root==null) return res;
        helper(root, target);
        return res;
    }
    void helper(TreeNode root, int target){
        if(root==null) return;
        target-=root.val;
        list.add(root.val);
        if(target== 0&& root.left==null&& root.right==null) res.add(new ArrayList(list));
        helper(root.right,target);
        helper(root.left,target);
        list.remove(list.size() - 1);
    }
}
