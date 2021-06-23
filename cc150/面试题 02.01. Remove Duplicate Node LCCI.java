/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head==null) return head;
        ListNode cur=head;
        Set<Integer> set=new HashSet<>();
        set.add(cur.val);
        while(cur.next!=null){
            if(set.contains(cur.next.val)){
                cur.next=cur.next.next;
            }else {
                set.add(cur.next.val);
                cur=cur.next;
            }
        }
        return head;
    }
}
