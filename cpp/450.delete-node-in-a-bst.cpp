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
    TreeNode * get_succesor(TreeNode *current){
	    while(current && current->left) current = current->left;
	    return current;
    }
    TreeNode *solve(TreeNode* current, int key){
	    if(!current) return NULL;// not found;
	    if(key < current->val) current->left = solve(current->left, key);
	    else if(key > current->val) current->right =  solve(current->right, key);
	    else{
	    if(current->left && current->right){
	       TreeNode *to_change = get_succesor(current->right);
	       current->val = to_change->val;
	       current->right = solve(current->right, to_change->val);
	    }else if(!current->left && !current->right){
		    delete current;
		    return NULL;
	    }else if(current->left){
	       auto tmp = current->left;
	       delete current;
	       return tmp;
	    }else{
	       auto tmp = current->right;
	       delete current;
	       return tmp;
	    }
	    }
	    return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
	   return solve(root, key);
    }
};
