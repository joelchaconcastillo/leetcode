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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode * get_middle(ListNode *head){
	    // 1 2 3 4
	    //     s
	    //         f
	    ListNode *prev = NULL;
	    auto slow = head;
	    auto fast = head;
	    while(fast && fast->next){
		 prev = slow;
		 slow = slow->next;
		 fast = fast->next->next;
	    }
	    return prev;
    }
    TreeNode* helper(ListNode *head){
	    if(!head) return NULL;
	    if(head && !head->next){
		    return new TreeNode(head->val);
	    }
	    auto preMiddle = get_middle(head);
	    auto middle = preMiddle->next;
	    preMiddle->next = NULL;
	    TreeNode *current = new TreeNode(middle->val);
	    current->left = helper(head);
	    current->right = helper(middle->next);
	    return current;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       return helper(head);	    
    }
};
