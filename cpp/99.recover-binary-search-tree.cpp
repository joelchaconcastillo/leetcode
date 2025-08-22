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
    void helper(TreeNode *current, vector<pair<int, TreeNode*>> &tmp){
	    if(!current)return;
	    helper(current->left, tmp);
	    tmp.push_back({current->val, current});
	    helper(current->right, tmp);
    }
    void solve1(TreeNode *current){
	    vector<pair<int, TreeNode*>> tmp;
	    helper(current, tmp);
	    auto cpy = tmp;
	    sort(cpy.begin(), cpy.end());
	    vector<int>idxs;
	    for(int i = 0 ; i < tmp.size(); i++){
		    if(tmp[i]!=cpy[i])idxs.push_back(i);
	    }
	    swap(tmp[idxs[0]].second->val, tmp[idxs[1]].second->val);
    }
    
    void helper2(TreeNode *current, vector<TreeNode*> &wrong_nodes, TreeNode * & prev){
	    if(!current) return;
	    helper2(current->left, wrong_nodes, prev);
	    if(prev && prev->val > current->val){
		    if(wrong_nodes.empty()) wrong_nodes = {prev, current};
		    else wrong_nodes[1] = current;
	    }
	    prev = current;
	    helper2(current->right, wrong_nodes, prev);
    }
    void solve2(TreeNode *current){
	    vector<TreeNode*> wrong_nodes;
	    TreeNode * prev = NULL;
	    helper2(current, wrong_nodes, prev);
	    if(wrong_nodes.size() == 2 && wrong_nodes[0] && wrong_nodes[1])
	    swap(wrong_nodes[0]->val, wrong_nodes[1]->val);
    }
    void recoverTree(TreeNode* root) {
	solve2(root);
//        solve1(root);
    }
};
