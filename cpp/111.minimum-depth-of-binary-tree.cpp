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
    //time: O(n)
    //space: O(max h)
    //elased time to solve: 2 min.
    int solve(TreeNode *root, int depth=1){
	if(!root->left && !root->right) return depth;
	int minDepth = INT_MAX;
	if(root->left) minDepth = min(minDepth, solve(root->left, depth+1));
	if(root->right) minDepth = min(minDepth, solve(root->right, depth+1));
	return minDepth;
    } 
    int minDepth(TreeNode* root) {
	    if(!root)return 0;
       return solve(root);	    
    }
};
