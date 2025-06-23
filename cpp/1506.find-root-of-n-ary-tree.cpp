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
    Node* solve(vector<Node*> &tree){
	    unordered_map<Node*, int> inDegree;
	    for(auto i:tree)inDegree[i]=0;
	    for(auto i:tree){
		    for(auto childre:i->children){
			    inDegree[childre]++;
		    }
	    }
	    for(auto [node, count]:inDegree) if(count==0)return node;
	    return NULL;
    }
    Node* findRoot(vector<Node*> tree) {
        return solve(tree);	    
    }
};
