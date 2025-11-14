/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * helper(TreeNode *current, int val){
	    if(!current)return NULL;
	    if(!current->left && !current->right){
		    if(current->val <=val)return NULL;
		    return current;
	    }
	    TreeNode * tmp = NULL;
	    if(current->val > val)tmp = current;
	    if(val < current->val){
		    auto left = helper(current->left, val);
		    if(!tmp && left){
			    if(left->val > val)tmp=left;
		    }else if(tmp && left){
			    if(left->val < tmp->val && left->val > val)tmp = left;
		    }
		    return tmp;
	    }
	    auto right = helper(current->right , val);
	    if(!tmp && right){
			    if(right->val > val)tmp=right;
		    }else if(tmp && right){
			    if(right->val < tmp->val && right->val > val)tmp = right;
		    }
		    return tmp;

    }
    TreeNode* solve_optimized(TreeNode* root, TreeNode* p) {
	    TreeNode *res= NULL;
	    while(root){
		    if( p->val >= root->val){
			    root = root->right;
		    }else{
			    res = root;
			    root = root->left;
		    }
	    }
	    return res;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	    return solve_optimized(root, p);
//	    return helper(root, p->val);
    }
};
