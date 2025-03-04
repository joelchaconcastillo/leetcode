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
       time: O(n) n --> # of nodes
       space: O(n)
       time elapsed: 6 min.
     */
    int solve(TreeNode * current, int &maxDiam){
	int l=0, r=0;
	if(current->left) l = solve(current->left, maxDiam)+1;
	if(current->right) r = solve(current->right, maxDiam)+1;
	maxDiam = max(l+r, maxDiam);
	return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
	int res = 0;
        solve(root, res);
	return res;
    }
};
