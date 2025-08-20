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
    void print(ListNode*head){
	    while(head){
		    cout << head->val<<" ";
		    head = head->next;
	    }
	    cout << endl;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prehead = new ListNode(INT_MIN);	    
	// [M  -1  3  5  4  0   N]
	// [M  -1  3  4  0  5  N]
	//         pr    n
	//         p  n
	//     cp  n
	//            ne
	prehead->next = head;
	auto prev = prehead;
	while(prev->next){
	      if(prev->next->val >= prev->val){
		      prev = prev->next;
		      continue;
	      }
	      //remove next item
	      auto pivot = prev->next;
	      prev->next = prev->next->next;
	      //search its place
	      auto current_prev = prehead;
	      while(current_prev->next->val < pivot->val){
		      current_prev = current_prev->next;
	      }
	      //insert it
	      pivot->next = current_prev->next;
	      current_prev->next = pivot;

	}
	return prehead->next;
    }
};
