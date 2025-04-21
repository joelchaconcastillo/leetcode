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
    ListNode* solve1(vector<ListNode*> &lists){
	    priority_queue<tuple<int, ListNode*>> pq;
	    for(auto list:lists){
		    if(!list)continue;
		    pq.push({-list->val, list});
	    }
	    ListNode * res = new ListNode();
	    ListNode *current = res;
	    while(!pq.empty()){
		 auto [val, ptr] = pq.top(); pq.pop();
		 current->next = ptr;
		 current = current->next;
		 ptr = ptr->next;
		 if(!ptr)continue;
		 pq.push({-ptr->val, ptr});
	    }
	    return res->next;

    }
    ListNode* solve2(vector<ListNode*> &lists){
	    int k = lists.size();
	    ListNode * dummy = new ListNode();
	    ListNode * current = dummy;
	    while(true){
	       pair<int, int> min_node(INT_MAX, 0);
	       for(int i = 0 ; i < lists.size(); i++){
		      if(!lists[i])continue;
		      min_node = min(min_node, {lists[i]->val, i});
	       }
	       if(min_node.first == INT_MAX)break;
	       current->next = lists[min_node.second];
	       current = current->next;
	       lists[min_node.second] = lists[min_node.second]->next;
	    }
	    return dummy->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	    return solve2(lists);
    }
};
