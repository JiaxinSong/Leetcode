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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null)
            q.offer(root);
        while (!q.isEmpty())
        {
            int cur_len = q.size();
            int cur = Integer.MIN_VALUE;
            for (int e = 0; e < cur_len; e ++)
            {
                TreeNode x = q.poll();
                cur = Math.max(cur, x.val);
                if (x.left != null)
                    q.offer(x.left);
                if (x.right != null)
                    q.offer(x.right);
            }
            res.add(cur);
        }

        return res;
    }
}
