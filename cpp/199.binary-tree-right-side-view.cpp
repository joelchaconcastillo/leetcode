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
    void dfs_transversal(TreeNode *current, vector<int> &res, int level=0){
       if(!current)return; //no solution edge case
       if(res.size() <= level){
          res.push_back(current->val);
       }else{
          res[level] = current->val;
       }

       dfs_transversal(current->left, res, level+1);
       dfs_transversal(current->right, res, level+1);
    }
    vector<int> solve1(TreeNode *root){
       vector<int> res;
       dfs_transversal(root, res);
       return res;

    }
    vector<int> solve2(TreeNode *root){
	  if(!root)return {};
	  queue<TreeNode*> q;
          q.push(root);
          vector<int> res;
    while(!q.empty()){
       queue<TreeNode*> tmp_queue;
       int last_val_level = -1;//
       while(!q.empty()){
          auto current = q.front(); q.pop();
          last_val_level = current->val;
          if(current->left) tmp_queue.push(current->left);
          if(current->right) tmp_queue.push(current->right);
       }
       q = tmp_queue;
       if(last_val_level!=-1) res.push_back(last_val_level);
     }
      return res;

    }
    vector<int> rightSideView(TreeNode* root) {
	   return solve2(root);
    }
};
