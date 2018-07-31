/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

    	if(!head || !head->next) return head;

    	ListNode dummy(-1);
    	ListNode* cur = head;

    	while(cur)
    	{
    		ListNode* next = cur->next;
    		ListNode* pre = &dummy;//刚开始排序链表为空
    		while(pre->next && pre->next->val <= cur->val)
    		{
    			pre = pre->next;
    		}

    		cur->next = pre->next;
    		pre->next = cur;
    		cur = next;
    	}

    	return dummy.next;
        
    }
};
