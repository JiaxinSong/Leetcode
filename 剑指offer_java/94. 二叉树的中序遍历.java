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
    public int kthLargest(TreeNode root, int k) {
        Deque<TreeNode> deque=new LinkedList<>();
        TreeNode cur= root;
        while(!deque.isEmpty()||cur!=null){
            while(cur!=null){
                deque.push(cur);
                cur=cur.right;
            }
            cur=deque.poll();
            k--;
            if(k==0) return cur.val;
            cur=cur.left;   
        }
        return 1;

    }
}
