class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head || k == 0) return nullptr; // 鲁棒性1、2
        ListNode *fast = head, *slow = head;
        for(int i=1; i<=k-1; ++i)
        {
            if(fast -> next) fast = fast -> next; // 鲁棒性3
            else return nullptr;
        }
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};
