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
    vector<ListNode*> solve(ListNode *head){
	    auto current = head;
	    // 1 2 n:2
	    // i
	    int n = 0;
	    do{
		 current = current->next;
		 n++;
	    }while(current!=head);
	    auto tail1 = current;
	    auto tail2 = current;
	    for(int i = 0; i+1 < ceil(n/2.0); i++) tail1 = tail1->next;
	    for(int i = 0; i+1 < n; i++) tail2 = tail2->next;
	    auto head2 = tail1->next;
	    tail1->next = head;
	    tail2->next = head2;
	    return {head, head2};
    }
    vector<ListNode*> solve2(ListNode* list){
	    ListNode * slow = list, * fast = list;
	    //0 1 2 4
	    //  s
	    //      f 
	    while(fast->next != list && fast->next->next != list){
		    slow = slow->next;
		    fast = fast->next->next;
	    }
	    if(fast->next!=list)fast = fast->next;
	    fast->next = slow->next;
	    slow->next = list;
	    return {list, fast->next};
    }
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
	    return solve2(list);
    }
};
