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
    int min_swaps(vector<int> &vals){
	    int n = vals.size();
	    vector<pair<int, int> > val_index;
	    for(int i = 0 ; i < n ;i++){
		    val_index.push_back({vals[i], i});
	    }
	    sort(val_index.begin(), val_index.end());
	    vector<bool> visited(n, false);
	    int res = 0;
	    for(int i = 0 ; i < n; i++){
		    if(visited[i] || i == val_index[i].second) continue;
		    int index = i, _swaps = 0 ;
		    while(!visited[index]){
			    visited[index] = true;
			    index = val_index[index].second;
			    _swaps++;
		    }
		    if(_swaps>1)
		    res += _swaps-1;
	    }
	    return res;
    }
    int solve(TreeNode *root){
	    queue<TreeNode*>q;
	    q.push(root);
	    int res = 0;
	    while(!q.empty()){
		    vector<int> vals;
		    int q_size = q.size();
		    for(int i = 0 ; i < q_size; i++){
			    auto current = q.front(); q.pop();
			    vals.push_back(current->val);
			    if(current->left)q.push(current->left);
			    if(current->right)q.push(current->right);
		    }
		    res += min_swaps(vals);
	    }
	    return res;
    }
    int minimumOperations(TreeNode* root) {
       return solve(root);
    }
};
