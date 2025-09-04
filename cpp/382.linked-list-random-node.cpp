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
    ListNode * head;
    Solution(ListNode* head):head(head) {
    }
    
    int getRandom() {
	    auto picked = head->val;
	    auto tmp = head->next;
	    int i = 2;
	    while(tmp){
		    if(rand()%i == 0) picked=tmp->val;
		    tmp  = tmp->next;
		    i++;
	    }
	    return picked;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
