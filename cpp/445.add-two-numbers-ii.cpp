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
    int get_size(ListNode* head){
	    int n = 0;
	    while(head){
		    head = head->next;
		    n++;
	    }
	    return n;
    }
    pair<ListNode*, int> dfs(int n, int m, ListNode *L1, ListNode *L2){
	    if(n==0 && m==0)return {NULL,0};
	    if(n>m){
		    int val = L1->val;
		    auto tmp = dfs(n-1, m, L1->next, L2);
		    val += tmp.second;
	            ListNode * sum = new ListNode(val%10, tmp.first);
		    return {sum, val/10};
	    }else if(m>n){
		    int val = L2->val;
		    auto tmp = dfs(n, m-1, L1, L2->next);
		    val += tmp.second;
	            ListNode * sum = new ListNode(val%10, tmp.first);
		    return {sum, val/10};
	    }else{
		    int val = L1->val+L2->val;
		    auto tmp = dfs(n-1, m-1, L1->next, L2->next);
		    val += tmp.second;
	            ListNode * sum= new ListNode (val%10, tmp.first);
		    return {sum, val/10};
	    }
    }
    ListNode* solve(ListNode* L1, ListNode* L2){
	    int n = get_size(L1), m = get_size(L2);
	    auto res = dfs(n,m, L1, L2);
	    if(res.second){
		    ListNode* sum = new ListNode(res.second, res.first);
		    return sum;
	    }
	    return res.first;
    }
    ListNode* reverseList(ListNode *head){
	    ListNode *prev = NULL, *current = head;
	    while(current){
		    auto next = current->next;
		    current->next = prev;
		    prev =  current;
		    current = next;
	    }

	    return prev;
    }
    ListNode* solve2(ListNode* L1, ListNode *L2){
	    L1 = reverseList(L1);
	    L2 = reverseList(L2);
	    auto currentl1 = L1;
	    auto currentl2 = L2;
	    ListNode * link = new ListNode();
	    auto newhead = link;
	    int rem = 0;
	    while(currentl1 || currentl2){
		    int val = rem;
		   if(currentl1) val+=currentl1->val;
		   if(currentl2) val+=currentl2->val;
		    link->next = new ListNode(val%10);
		    rem  = val/10;
		    if(currentl1)
		    currentl1 = currentl1->next;
		    if(currentl2)
		    currentl2 = currentl2->next;
		    link = link->next;
	    }
	    if(rem) link->next = new ListNode(rem);
	    auto res = reverseList(newhead->next);
	    return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	    return solve2(l1, l2);
	    return solve(l1, l2);
    }
};
