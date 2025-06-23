/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node *> path1, path2;
	auto tmp_p = p, tmp_q = q;
	while(tmp_p) path1.push_back(tmp_p), tmp_p = tmp_p->parent;
	while(tmp_q) path2.push_back(tmp_q), tmp_q = tmp_q->parent;
	reverse(path1.begin(), path1.end());
	reverse(path2.begin(), path2.end());
	auto prev = path1.front();
	for(int i = 0 ; i < min(path1.size(), path2.size()); i++){
		if(path1[i]!=path2[i]) return prev;
		prev = path1[i];
	}
	return prev;
    }
};
