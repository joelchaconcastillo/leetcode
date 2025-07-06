/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool allSame(vector<vector<int> > &grid, int x1, int y1, int len){
	    for(int i = x1; i < x1+len; i++){
		    for(int j = y1; j < y1+len; j++){
			    if(grid[i][j]!=grid[x1][y1]){
				    return false;
			    }
		    }
	    }
	    return true;
    }
    Node* solve(vector<vector<int> > &grid, int x1, int y1, int len){
	    if(allSame(grid, x1, y1, len)){
		    return new Node(grid[x1][y1], true);
	    }else{
		    Node *root = new Node(false, false);
		    root->topLeft= solve(grid, x1, y1, len/2);
		    root->topRight= solve(grid, x1, y1+len/2, len/2);
		    root->bottomLeft= solve(grid, x1+len/2, y1, len/2);
		    root->bottomRight= solve(grid, x1+len/2, y1+len/2, len/2);
		    return root;
	    }
    }
    Node* construct(vector<vector<int>>& grid) {
           return solve(grid, 0, 0, grid.size());
    }
};
