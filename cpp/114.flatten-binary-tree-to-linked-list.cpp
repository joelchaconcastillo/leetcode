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
    TreeNode * transverse(TreeNode *current){
	 if(!current) return NULL;
	 TreeNode *_left = current->left, *_right = current->right;
	 current->left = NULL;
	 if(_left){
		 current->right = _left;
		 current = transverse(_left);
	 }
	 if(_right){
		 current->right = _right; 
		 current = transverse(_right);
	 }
	 return current;
    }
    void solve(TreeNode *root){
	 transverse(root);
    }
    void solve2(TreeNode *root){
	 auto current = root;
	 while(current){
	     if(current->left){
		  auto tmp = current->left;
		  while(tmp->right)tmp = tmp->right;
		  auto _left = current->left;
		  auto _right = current->right;
		  current->left = NULL;
		  current->right = _left;
		  tmp->right = _right;
	     }
	     current = current->right;
	 }
    }
    void flatten(TreeNode* root) {
	 solve2(root);
	 solve(root);
    }
};
