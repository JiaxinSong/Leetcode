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
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        int depth=0;
        Deque<TreeNode> deque=new LinkedList<>();
        deque.push(root);
        while(!deque.isEmpty()){
            depth++;
            int size=deque.size();
            for(int i=0;i<size;i++){
                TreeNode x=deque.poll();
                if(x.left!=null) deque.add(x.left);
                if(x.right!=null) deque.add(x.right);
            }
        }

        return depth;
    }
}
