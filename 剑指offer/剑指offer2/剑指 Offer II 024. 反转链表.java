/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        
        ListNode a=null, b=head;
        if(b==null) return null;
        while(b!=null){
            ListNode x=b.next;
            b.next=a;
            a=b;
            b=x;
        }
        return a;
    }
}
