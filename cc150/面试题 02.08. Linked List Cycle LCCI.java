/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null) return null;
        ListNode fast=head,slow=head;
        while(fast!=null){
            slow =slow.next;
            if(fast.next!=null) fast=fast.next;
            else return null;
            if(fast==slow){
                ListNode ptr=head;
                while(ptr!=slow){
                    ptr=ptr.next;
                    slow=slow.next;
                }
                return ptr;
            }


        }
        return null;
    }
}
