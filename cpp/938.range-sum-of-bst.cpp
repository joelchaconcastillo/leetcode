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
    /*
     *   time: best: O(K), worst: O(N)
     *   space: best: O(log k) worst: O(N)
     * */
    int helper(TreeNode *node, int low, int high){
	  if(!node)return 0;
	  int sum = node->val >=low && node->val <=high?node->val:0;
	  if(node->val>=low)
	  sum += helper(node->left, low, high);
	  if(node->val<=high)
	  sum += helper(node->right, low, high);
	  return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
	   return helper(root, low, high); 
    }
};
