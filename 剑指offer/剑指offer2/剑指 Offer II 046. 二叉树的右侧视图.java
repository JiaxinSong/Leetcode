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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res= new ArrayList<>();
        if(root==null) return res;
        Deque<TreeNode> que= new LinkedList<>();
        que.offer(root);
        while(!que.isEmpty()){
            int s=que.size();
            for(int i=0;i<s;i++){
                TreeNode t=que.poll();
                if(i==s-1) res.add(t.val);
                if(t.left!=null) que.offer(t.left);
                if(t.right!=null) que.offer(t.right);
            }
        }
        return res;
    }
}
