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
    public int[] levelOrder(TreeNode root) {
        if(root==null) return new int[]{};
        Deque<TreeNode> deque=new LinkedList<TreeNode>();
        ArrayList<Integer> ans=new ArrayList<Integer>();
        deque.add(root);
        while(!deque.isEmpty()){
            TreeNode x=deque.pop();
            ans.add(x.val);
            if(x.left!=null) deque.add(x.left);
            if(x.right!=null) deque.add(x.right); 
        }
        int[] res=new int[ans.size()];
        for(int i=0;i<ans.size();i++){
            res[i]=ans.get(i);
        }
        return res;
    }
}
