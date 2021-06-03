/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node,Node> map=new HashMap<>();
        if(head==null) return head;
        Node x=head;
        while(x!=null){
            map.put(x,new Node(x.val));
            x=x.next;
        }
        x=head;
        while(x!=null){
            map.get(x).next=map.get(x.next);
            map.get(x).random=map.get(x.random);
            x=x.next;
        }

        return map.get(head);
    }
}
