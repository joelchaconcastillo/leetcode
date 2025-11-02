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
    bool solve(ListNode *head){
	 if(!head)return false;
	 ListNode *slow = head, *fast = head;
	 do{
	       if(!slow || !slow->next)return false;
	       slow = slow->next;
	       if(!fast || !fast->next || !fast->next->next)return false;
	       fast = fast->next->next;
	 }while(slow != fast);
	 return slow;
    }
    bool hasCycle(ListNode *head) {
         return solve(head);	    
    }
};
