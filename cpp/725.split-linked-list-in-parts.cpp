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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto current = head;
        while(current){
		n++;
		current = current->next;
	}	
	current = head;
	int _size = max(1,n/k), spared = n%k;
	vector<ListNode*> res(k, NULL);
	ListNode * prev = NULL;
	int i = 0;
	while(current){
		res[i++] = current;
		int j = 0;
		while(j < _size){
			prev = current;
			current = current->next;
			j++;
		}
		if(spared > 0 && n>=k){
			prev = current;
			if(current)
			current = current->next;
		}	
		if(prev)
		prev->next = NULL;
		spared--;
	}
	return res;
    }
};
