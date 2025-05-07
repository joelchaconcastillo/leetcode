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
    vector<int> transverse(TreeNode *current){
	  if(!current)return {};
	  vector<int> left = transverse(current->left);
	  vector<int> right = transverse(current->right);
	  vector<int> res(left.begin(), left.end());
	  res.push_back(current->val);
	  for(auto i:right)res.push_back(i);
	  return res;
    }
    vector<int> solve(TreeNode* r1, TreeNode *r2){
	  auto list1 = transverse(r1);
	  auto list2 = transverse(r2);
	  vector<int> res;
	  int i = 0, j = 0;
	  while(i < list1.size() && j < list2.size()){
	       if( list1[i] <= list2[j] ) res.push_back(list1[i++]);
	       else res.push_back(list2[j++]);
	  }
	  while(i < list1.size()) res.push_back(list1[i++]);
	  while(j < list2.size()) res.push_back(list2[j++]);
	  return res;
    }
    void pushLeft(TreeNode *current, vector<TreeNode*>&current_path){
	    while(current){
		    current_path.push_back(current);
		    current = current->left;
	    }
    }
    vector<int> solve2(TreeNode *root1, TreeNode *root2){
	   vector<TreeNode *> path1, path2;
	   pushLeft(root1, path1);
	   pushLeft(root2, path2);
	   vector<int> res;
	   while(!path1.empty() || !path2.empty()){
		TreeNode *current;
		if(!path1.empty() && !path2.empty()){
		    if(path1.back()->val <= path2.back()->val){
			    current = path1.back();
			    path1.pop_back();
		            pushLeft(current->right, path1);
		    }
		    else{
			    current = path2.back();
			    path2.pop_back();
		            pushLeft(current->right, path2);
		    }
		}else{
		   if(!path1.empty()){
			   current = path1.back(); path1.pop_back();
		            pushLeft(current->right, path1);
		   }else{
			   current = path2.back(); path2.pop_back();
		            pushLeft(current->right, path2);
		   }
		}
		res.push_back(current->val);
	   }
	   return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	  //return solve(root1, root2);
	  return solve2(root1, root2);
    }
};
