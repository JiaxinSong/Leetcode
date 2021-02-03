class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;
        if(head->val == val) return head->next;
        //递归删除
        head->next = deleteNode(head->next,val);
        return head;
    }
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        while(prev && prev -> next) {
            if(prev -> next -> val == val) {
                prev -> next = prev -> next -> next;
                break;
            }
            prev = prev -> next;
        }
        return dummy -> next;
    }
};
