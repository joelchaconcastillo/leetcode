/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    typedef unordered_map<Node *, vector<Node*>> adjList_type;
    pair<int, Node *> BFS(Node *current){
	    queue<Node*> q;
	    q.push(current);
	    int res = 0;
	    Node *last=current;
	    while(!q.empty()){
		    queue<Node*>tmp;
		    res++;
		    while(!q.empty()){
		       auto current = q.front(); q.pop();
		       last = current;
		       for(auto to:current->children){
			       q.push(to);
		       }
		    }
		    q=tmp;
	    }
	    return {res, last};
    }
    int solve(Node *root){
	    auto [jump1, extremeNode1] = BFS(root);
	    auto [jump2, extremeNode2] = BFS(root);
	    return max(jump1, jump2);
    }
    int dfs(Node *current, int &res){
	    if(!current) return 0;
	    int maxDepth = 0;
	    priority_queue<int> depths;
	    for(auto _to:current->children){
		    auto to_depth = 
			    dfs(_to, res)+1;
		    depths.push(to_depth);
		    maxDepth = max(maxDepth, to_depth);
	    }
	    if(depths.size() >= 2){
		    auto a = depths.top(); depths.pop();
		    auto b = depths.top(); depths.pop();
		    res = max(res, a+b);
	    }else if(depths.size() == 1){
		    res = max(res, depths.top());
	    }
	    return maxDepth;
    }
    int solve2(Node * root){
	    int res = 0 ;
	    dfs(root, res);
	    return res;
    }
    int diameter(Node* root) {
	    return solve2(root);
	    return solve(root);
    }
};
