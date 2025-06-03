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
    ListNode *solve(ListNode* head){
       if(!head)return head;
       if(!head->next)return NULL;
       auto slow = head->next;
       if(!head->next->next)return NULL;
       auto fast = head->next->next;
       while(slow != fast){
	    slow = slow->next;
	    if(!slow)return NULL;
	    if(!fast->next || !fast->next->next)return NULL;
	    fast = fast->next->next;
       }
       slow = head;
       while(slow != fast){
	    slow = slow->next;
	    fast = fast->next;

       }
       return slow;
    }
    ListNode *detectCycle(ListNode *head) {
	return solve(head);
    }
};
