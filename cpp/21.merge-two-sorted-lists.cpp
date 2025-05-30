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
    ListNode* solve(ListNode* list1, ListNode* list2){
	    ListNode *res = new ListNode();
	    ListNode *head = res;
	    while(list1 && list2){
		    if(list1->val < list2->val){
		       res->next = list1;
		       list1 = list1->next;
		    }else{
		      res->next = list2;
		      list2 = list2->next;
		    }
		    res = res->next;
	    }
	    while(list1){
		  res->next = list1;
		  res = res->next;
		  list1 = list1->next;
	    }
	    while(list2){
		  res->next = list2;
		  res = res->next;
		  list2 = list2->next;
	    }
	    return head->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	   return solve(list1, list2);
    }
};
