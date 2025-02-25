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
time: O(n): n is the number of nodes
space: O(max depth)
time solving it: 24 min 
 * */
    pair<int, TreeNode*> solve(TreeNode *current, int level=0){
	  if(!current)return {level, current};
	  pair<int, TreeNode*> deepest_node(level, current);
	  if(current->left){
	      deepest_node = solve(current->left, level+1);
	  }
	  if(current->right){
	      auto tmp = solve(current->right, level+1);
	      if(tmp.first > deepest_node.first) return tmp;
	      else if(tmp.first == deepest_node.first) return {tmp.first, current};
	  }
	  return deepest_node;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
	return solve(root).second;
    }
};
/*
 

   left --> largest, lca
   right --> largest, lca
   
   if largest on right > largest on left:
       return largest, lca on right
   els eif larges on right < larges on left
       return largest, lca on left
   else 
       return largest, this node is lca
 3
    5
       6  
       2
          7
	  4
    1
       0
       8


 



 * */
