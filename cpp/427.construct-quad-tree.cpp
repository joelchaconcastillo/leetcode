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
    bool allEqual(vector<vector<int> > &grid, int row, int col, int len){
	    bool same = true;
	    for(int i = row; i < row+len; i++){
		    for(int j = col; j < col+len; j++){
			    if(grid[i][j] != grid[row][col]) return false;
		    }
	    }
	    return same;
    }
    Node *buildQT(vector<vector<int> > &grid, int row, int col, int len){
	    if(allEqual(grid, row, col, len)){
		    return new Node(grid[row][col], true);
	    }else{
		    Node * current = new Node(false, false);
		    current->topLeft = buildQT(grid, row, col, len/2);
		    current->topRight = buildQT(grid,row, col+len/2, len/2 );
		    current->bottomLeft = buildQT(grid, row+len/2, col, len/2);
		    current->bottomRight = buildQT(grid,row+len/2, col+len/2, len/2); 
		    return current;
	    }
    }
    Node *solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    return buildQT(grid, 0, 0, n);
    }
    Node* construct(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
