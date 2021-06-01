/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode cur1=null;
        ListNode cur2=head;
        while(cur2!=null){
            ListNode tmp=cur2.next;
            cur2.next=cur1;
            cur1=cur2;
            cur2=tmp;
        }
        return cur1;
    }
}
