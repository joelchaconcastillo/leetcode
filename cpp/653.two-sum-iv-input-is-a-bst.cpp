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
    bool find(TreeNode *current, int k){
	    if(!current) return false;
	    if(current->val==k)return true;
	    if(k<current->val) return find(current->left, k);
	    return find(current->right, k);
    }
    bool solve(TreeNode *root, int k){
	    queue<TreeNode *> q;
	    q.push(root);
	    while(!q.empty()){
		    auto current = q.front(); q.pop();
		    int rem = k-current->val;
		    
		    if(rem!=current->val && find(root, rem))return true;
		    if(current->left)q.push(current->left);
		    if(current->right)q.push(current->right);
	    }
	    return false;
    }
    bool findTarget(TreeNode* root, int k) {
	    return solve(root, k);
    }
};
