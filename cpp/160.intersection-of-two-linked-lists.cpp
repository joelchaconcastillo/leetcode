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
    ListNode * reverse(ListNode *ptr){
	    //      1  2  3 null
	    //            p c
	    //  3-> 2 -> 1 -> NULL
	    //   
	    // c->next = prev
	    // prev = c
	    // c = n
	    ListNode *prev= NULL;
	    while(ptr){
	       auto _next = ptr->next;
	       ptr->next = prev;
	       prev = ptr;
	       ptr = _next;
	    }
	    return prev;
    }
    ListNode *solve(ListNode *a, ListNode *b){
	   auto ptr_a = a;
	   while(ptr_a){
		 ptr_a->val *=-1;
		 ptr_a = ptr_a->next;
	   }
	   ListNode *res = NULL;
	   auto ptr_b = b;
	   while(ptr_b && !res){
		   if(ptr_b->val < 0) res = ptr_b;
		   ptr_b = ptr_b->next;
	   }
	   auto fix_ptr = a;
	   while(fix_ptr){
		 fix_ptr->val *=-1;
		 fix_ptr = fix_ptr->next;
	   }
	   return res;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return solve(headA, headB);
    }
};
