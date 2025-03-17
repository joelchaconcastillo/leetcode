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
    void reverse_level_by_reference(vector<TreeNode *> &nodes_on_level, unordered_map<TreeNode*, TreeNode*> &parent){
	 int  n = nodes_on_level.size(), i = 0, j = n-1;
	 while( i < j ){
		 //swap links from parents
		 if(i%2==0){
		    swap(parent[nodes_on_level[i]]->left, parent[nodes_on_level[j]]->right);
		 }else{
		    swap(parent[nodes_on_level[i]]->right, parent[nodes_on_level[j]]->left);
		 }
		 swap(nodes_on_level[i]->left, nodes_on_level[j]->left);
		 swap(nodes_on_level[i]->right, nodes_on_level[j]->right);
		 i++, j--;
	 }
    }
    void reverse_level(vector<TreeNode*> &nodes_on_level, unordered_map<TreeNode*, TreeNode*> & parent){
	  int n = nodes_on_level.size();
	  int i = 0, j = n-1; 
	  while(i<j){
	     swap(nodes_on_level[i++]->val, nodes_on_level[j--]->val);
	  }
    }
    // time: O(n) --> where n is the number of nodes
    // space: O(n) a better lower bound might be O(2^(log_2(n))) --> the number of nodes at the last level
    //   2 4 8 16 .. 30 log_2(n) --> 2^log_2(n) 
    //
    // elapsed time to solve it: 6 min.:
    TreeNode* solve(TreeNode *root){
       queue<TreeNode*> q;
       unordered_map<TreeNode*, TreeNode*> parent;
       q.push(root);
       int current_level = 1;
       while(!q.empty()){
	   queue<TreeNode *> next_q;
	   vector<TreeNode *> nodes_on_level;
	   while(!q.empty()){
	     auto current = q.front(); q.pop();
	     if(current->left){
		     nodes_on_level.push_back(current->left);
		     parent[current->left] = current;
		     next_q.push(current->left);
	     }
	     if(current->right){
		     nodes_on_level.push_back(current->right);
		     parent[current->right] = current;
		     next_q.push(current->right);
	     }
	   }
	   if(current_level%2==1){
	     reverse_level_by_reference(nodes_on_level, parent);
	   }
	   q = next_q;
	   current_level++;
       }
       return root;
    }	    
    TreeNode* reverseOddLevels(TreeNode* root) {
       return solve(root);	    
    }
};
