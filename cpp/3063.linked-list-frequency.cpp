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
    ListNode* solve(ListNode* head) {
	    unordered_map<int, int> freq;
	    auto current = head;
	    while(current){
		    freq[current->val]++;
		    current = current->next;
	    }
	    ListNode * prev = NULL, *newHead = NULL;
	    current = NULL;
	    for(auto [val, count]:freq){
		    current = new ListNode(count);
		    if(!newHead)newHead = current;
		    if(prev)prev->next = current;
		    prev = current;
	    }

	    return newHead;
    }
    ListNode* frequenciesOfElements(ListNode* head) {
	    return solve(head);
    }
};
