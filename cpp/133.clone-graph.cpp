/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
 *  time: O(N+E)
 *  space: O(N+E)
 * */
class Solution {
public:
    unordered_map<int, Node*> visited;
    void hard_create(int id){
	    if(!visited[id]) visited[id] = new Node(id);
    }
    Node * solveBFS(Node *node){
	 if(!node)return node;
	 queue<Node*> q;
	 q.push(node);
	 unordered_set<int>marked;
	 while(!q.empty()){
	    auto current = q.front(); q.pop();
	    if(marked.count(current->val))continue;
	    marked.insert(current->val);
	    hard_create(current->val);
	    for(auto _next : current->neighbors){
	       hard_create(_next->val);
	       visited[current->val]->neighbors.push_back(visited[_next->val]);
	       q.push(_next);
	    }
	 }
	 return visited[node->val];
    }
    unordered_map<int, Node*> marked;
    Node * solveDFS(Node *node){
	if(!node) return node;
	if(marked.count(node->val))return marked[node->val];
	Node *current = new Node(node->val);
	marked[node->val]=current;
	for(auto _next: node->neighbors){
	    current->neighbors.push_back(solveDFS(_next));
	}
	return current;
    }
    Node* cloneGraph(Node* node) {
//	 return solveBFS(node);
	 return solveDFS(node);
    }
};

/*
 
   1 ----------2
   |           |
   |           |
   4 ----------3

   1,  2,4   3
   1-2
   1-4
   2-1
   2-3
   4-1
   4-3
   3-2
   3-4
 * */
