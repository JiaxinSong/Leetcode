/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL)
			return NULL;
		//技巧在于建立start节点，这样返回start->next就是排序后的头节点
		ListNode* tail = head, * start = new ListNode(0);
		start->next = head;
		while (tail->next != NULL)
			tail = tail->next;
		return QuickSort(start, tail);
	}
	//快速排序head->next到tail的节点，其中head节点是为了方便比枢轴小的节点前移同时可以保持枢轴左右两边处于连接状态，属于无效节点不需要排序
	ListNode* QuickSort(ListNode* head, ListNode* tail)
	{
		if (head->next == tail || head == tail)
			return tail;
		else
		{
			//pre指向枢轴的左边最后一个节点，pivot为枢轴取第一个节点，end指向枢轴的右边最后一个节点
			ListNode* pre = head, * pivot = head->next, * end = head->next;
			//遍历枢轴右边所有的节点
			while (end->next != tail->next)
			{
				//比枢轴小的全部放到枢轴的前面
				if (end->next->val < pivot->val)
				{
					ListNode* cur = end->next;
					end->next = cur->next;
					pre->next = cur;
					pre = pre->next;
				}
				//比枢轴大的依然放在枢轴的后面，继续遍历下一个节点
				else
					end = end->next;
			}
			pre->next = pivot;    //保持左右两边连接	
			QuickSort(head, pre);  //继续递归枢轴左边的节点
			QuickSort(pivot, end);  //继续递归枢轴右边的节点
			return head->next;  //head是无效节点，最后返回head->next
		}
	}
};

