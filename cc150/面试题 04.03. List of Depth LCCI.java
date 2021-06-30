/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] listOfDepth(TreeNode tree) {
        if(tree==null) return new ListNode[0];
        List<ListNode> res= new ArrayList<>();
        Deque<TreeNode> deque= new LinkedList<>();
        deque.add(tree);
        while(!deque.isEmpty()){
            int n=deque.size();
            ListNode dummy=new ListNode(0);
            ListNode cur=dummy;
            while(n--!=0){
                TreeNode x=deque.poll();
                cur.next=new ListNode(x.val);
                cur=cur.next;
                if(x.left!=null) deque.add(x.left);
                if(x.right!=null) deque.add(x.right);
            }
            res.add(dummy.next);
        }
        return res.toArray(new ListNode[res.size()]);
    }
}
