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
    vector<int> solve(ListNode *head){
	    int _size = 0;
	    auto tmp = head;
	    while(tmp){
		    _size++;
		    tmp = tmp->next;
	    }
	    vector<pair<int, int>> st;
	    vector<int> res(_size, 0);
	    int i = 0;
	    ListNode *current = head;
	    while(current){
		    while(!st.empty() && st.back().second < current->val){
			    res[st.back().first] = current->val;
			    st.pop_back();
		    }
		    st.push_back({i,current->val});
		    current = current->next;
		    i++;
	    }
	    return res;
    }
    vector<int> nextLargerNodes(ListNode* head) {
	   return solve(head); 
    }
};
