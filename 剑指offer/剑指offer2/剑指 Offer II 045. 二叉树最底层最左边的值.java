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
    public int findBottomLeftValue(TreeNode root) {
        if(root==null) return 0;
        int res=root.val;
        Deque<TreeNode> deque= new LinkedList<>();
        deque.offer(root);
        while(!deque.isEmpty()){
            int s=deque.size();
            for(int i=0;i<s;i++){
                
                TreeNode t=deque.poll();
                if(i==0) res=t.val;
                if(t.left!=null)deque.offer(t.left);
                if(t.right!=null) deque.offer(t.right);
            }
        }
        return res;
    }
}
