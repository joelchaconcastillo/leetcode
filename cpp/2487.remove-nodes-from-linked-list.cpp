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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;
	ListNode* dummy = new ListNode();
	dummy->next = head;
	auto prev = dummy, current = head;
	unordered_set<ListNode*> to_remove;
	while(current){
		while(!stack.empty() && stack.back()->val < current->val){
			to_remove.insert(stack.back());
			stack.pop_back();
		}
		stack.push_back(current);
		prev = current;
		current = current->next;
	}
	current = head;
	prev = dummy;
	while(current){
		if(to_remove.count(current)){
			prev->next = current->next;
		}else prev =  current;
		current = current->next;
	}
	return dummy->next;
    }
};
