/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        if(head==null){
            head=new Node(insertVal);
            head.next=head;
            return head;
        }
        Node current =head;
        while(current.next!=head){
            if(current.val<=insertVal){
                if(current.next.val>insertVal) break;
                else if(current.next.val<current.val) break;
            }else{
                if(current.next.val<current.val&&insertVal<current.next.val) break;
            }
            current=current.next;
        }
        Node newNode=new Node(insertVal);
        newNode.next=current.next;
        current.next=newNode;
        return head;
    }
}
