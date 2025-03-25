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
    unordered_map<int, double> level_count, level_sum; 
    void transverse(TreeNode *node, int level=0){
	  if(!node)return;
	  level_count[level]++;
	  level_sum[level]+=node->val;
	  transverse(node->left, level+1);
	  transverse(node->right, level+1);
    }
    // time: O(n) where n is the number of nodes
    // space: O(h)  where h is the max height
    // elapsed time to solve: 2 min
    vector<double> solve(TreeNode *node){
	    transverse(node);
	    vector<double>res(level_count.size(), 0.0);
	    for(auto ii:level_count){
	       res[ii.first] = level_sum[ii.first]/ii.second;
	    }
	    return res;
    }
    vector<double> averageOfLevels(TreeNode* root) {
	    return solve(root);
    }
};
