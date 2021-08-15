/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        Node p = head;
        while (p != null) {
            if (p.child != null) {
                Node next = p.next;
                Node child = p.child;
                p.next = child;
                p.child = null;

                child.prev = p;
                while (child.next != null)
                    child = child.next;
                child.next = next;

                if (next != null)
                    next.prev = child;
            }
            p = p.next;
        }
        return head;
    }
}
