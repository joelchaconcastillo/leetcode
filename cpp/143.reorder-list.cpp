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
    void split(ListNode *current, ListNode* current1, ListNode* current2 ){
	 int n = 0;
	 auto tmp = current;
	 while(tmp) n++, tmp=tmp->next;
	 for(int i = 0 ; i < n/2+(n%2); i++){
	    current1->next = current;
	    current = current->next;
	    current1 = current1->next;
	 }
	 current2->next = current1->next;
	 current1->next = NULL;
    }
    ListNode *reverse(ListNode* current){
	   ListNode * prev = NULL;
	   while(current){
		auto _next = current->next; // p ->  a - > NULL
		current->next = prev;
		prev = current;
		current = _next;
	   }
	   return prev;
    }
    void merge(ListNode *current1, ListNode *current2){
	  ListNode *result = current1;
	  current1 = current1->next;
	  int i = 0;
	  while(current1 && current2){
	     if(i%2==0){
		  result->next = current2;
		  current2 = current2->next;
	     }else{
		  result->next = current1;
		  current1 = current1->next;
	     }
	     result = result->next;
	     i++;
	  }
	  if(current1)result->next = current1;
	  if(current2)result->next = current2;
    }
    void print(ListNode *current){
	 while(current){
		cout << current->val<<" " ;
		current = current->next;
	 }
	 cout <<endl;
    }
    void solve(ListNode *head){
	 ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
	 split(head, head1, head2);
//	 print(head1->next);
//	 print(head2->next);
	 head2->next = reverse(head2->next);
//	 print(head2->next);
	 merge(head1->next, head2->next);
    }
    void reorderList(ListNode* head) {
	 solve(head);
    }
};
