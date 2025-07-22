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
    int solve(TreeNode * root){
	    long long res = 0;
	    queue<tuple<TreeNode *, long long>> q;
	    q.push({root,0});
	    while(!q.empty()){
		    auto [current, sum] = q.front(); q.pop();
		    sum*=10;
		    sum+=current->val;
		    if(!current->left && !current->right) res+=sum;
		    if(current->left)q.push({current->left, sum});
		    if(current->right)q.push({current->right, sum});
	    }
	    return static_cast<int>(res);
    }
    int sumNumbers(TreeNode* root) {
	    return solve(root);
    }
};
