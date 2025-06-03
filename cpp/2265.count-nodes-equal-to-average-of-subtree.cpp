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
    tuple<int, int, int> transverse(TreeNode *root){
	  if(!root) return {0,0,0};
	  auto [left_sum, left_size, left_res] = transverse(root->left);
	  auto [right_sum, right_size, right_res] = transverse(root->right);
	  int _sum = left_sum+right_sum+root->val;
	  int _size = left_size+right_size+1;
	  int res = left_res + right_res;
	  if(root->val == _sum/_size)res++;
	  return {_sum, _size, res};
    }
    int solve(TreeNode* root){
	auto [_, _, res] = transverse(root);
	return res;
    }
    int averageOfSubtree(TreeNode* root) {
	return solve(root);
    }
};
