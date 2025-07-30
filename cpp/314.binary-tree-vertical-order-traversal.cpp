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

    vector<vector<int> > solve(TreeNode *root){
	    if(!root) return {};
	    vector<vector<int> > res;
	    queue<tuple<int, TreeNode *>>q;
	    unordered_map<int, vector<int> >levels;
	    q.push({0, root});
	    int min_col=INT_MAX, max_col=INT_MIN;
	    while(!q.empty()){
	            queue<tuple<int, TreeNode *>> tmp;
		    while(!q.empty()){
		      auto [col, current] = q.front(); q.pop();
		      min_col = min(min_col, col);
		      max_col = max(max_col, col);
		      levels[col].push_back(current->val);
		      if(current->left){
			      tmp.push({col-1, current->left});
		      }
		      if(current->right){
			      tmp.push({col+1, current->right});
		      }
		    }
		    q=tmp;
	    }
	    for(int i = min_col, j=0; i<=max_col; i++,j++){
		    res.push_back(levels[i]);
	    }
	    return res;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
	    return solve(root);
    }
};
