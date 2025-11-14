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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
	    auto current = new ListNode();
	    current->next = head;
	    while(current){
		  for(int i = 0; i < m && current; i++){
			  current = current->next;
		  }
		  auto prev = current;
		  for(int i = 0 ; i < n && current; i++){
			  current = current->next;
		  }
		  if(current)
		  prev->next = current->next;
		  else if(prev)prev->next=NULL;
	    }
	    return head;
    }
};
