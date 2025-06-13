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
    void dfs(TreeNode *current, unordered_map<TreeNode*, vector<TreeNode*>> &adjList){
	    if(!current)return ;
	    if(current->left){
		    adjList[current].push_back(current->left);
		    adjList[current->left].push_back(current);
		    dfs(current->left, adjList);
	    }
	    if(current->right){
		    adjList[current].push_back(current->right);
		    adjList[current->right].push_back(current);
		    dfs(current->right, adjList);
	    }
    }
    vector<int> solve(TreeNode* root, TreeNode* target, int k){
	    unordered_map<TreeNode*, vector<TreeNode*>> adjList;
	    dfs(root, adjList);
	    queue<tuple<TreeNode*, int> > q;
	    q.push({target, 0});
	    vector<int> res;
	    unordered_map<TreeNode*, bool> visited;
	    while(!q.empty()){
		    auto [current, dist] = q.front(); q.pop();
		    if(visited[current])continue;
		    if(dist==k) res.push_back(current->val);
		    visited[current]=true;
		    for(auto _to:adjList[current]){
			    if(visited[_to])continue;
			    q.push({_to, dist+1});
		    }
	    }
	    return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	    return solve(root, target, k);
    }
};
