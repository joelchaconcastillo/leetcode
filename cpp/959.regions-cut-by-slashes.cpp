class Solution {
public:
    int get_components(vector<vector<int>> &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<tuple<int, int> > directions = {
		    {0,-1}, {0,1}, {1,0}, {-1,0}
	    };
	    int components = 0;
	    for(int i = 0 ; i < n ;i++){
		    for(int j = 0 ; j < m; j++){
			    if(grid[i][j]!=0)continue;
			    queue<tuple<int, int> > q;
			    q.push({i,j});
			    components++;
			    while(!q.empty()){
				    auto [row, col] = q.front(); q.pop();
				    if(grid[row][col] != 0)continue;
				    grid[row][col]=1;
				    for(auto [delta_row, delta_col]:directions){
					    int next_row = delta_row+row, next_col = delta_col +col;
					    if(next_row <0 || next_row>=n)continue;
					    if(next_col<0 || next_col>=m)continue;
					    if(grid[next_row][next_col]!=0)continue;
					    q.push({next_row, next_col});
				    }
			    }
		    }
	    }
	    return components;
    }
    int solve(vector<string> &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int> > expanded_grid(3*n, vector<int> (3*m, 0));
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m ; j++){
			    if(grid[i][j] == '/'){
				    expanded_grid[i*3][j*3+2] = 1;
				    expanded_grid[i*3+1][j*3+1] = 1;
				    expanded_grid[i*3+2][j*3] = 1;
			    }else if(grid[i][j] == '\\'){
				    expanded_grid[i*3][j*3] = 1;
				    expanded_grid[i*3+1][j*3+1] = 1;
				    expanded_grid[i*3+2][j*3+2] = 1;
			    }
		    }
	    }
	    return get_components(expanded_grid);
    }
    int find(vector<int> &parents, int node){
	    if(parents[node] == -1) return node;
	    return parents[node] = find(parents, parents[node]);
    }
    int union_sets(vector<int> &parents, int node1, int node2){
	    int parent1 = find(parents, node1);
	    int parent2 = find(parents, node2);
	    if(parent1 == parent2) return 1;
	    parents[parent2] = parent1;
	    return 0;
    }
    int solve2(vector<string> &grid){
	    int n = grid.size(), pointsPerSide = n+1, totalPoints = pointsPerSide*pointsPerSide;
	    vector<int> parents(totalPoints, -1);
	    for(int i = 0 ; i < pointsPerSide; i++){//all nodes on the border belong to the same component
		    for(int j = 0 ; j < pointsPerSide; j++){
			    if( i==0 || j==0 || i==pointsPerSide-1 || j== pointsPerSide-1){
				    int point = i*pointsPerSide+j;
				    parents[point]=0;
			    }
		    }
	    }
	    parents[0] = -1;
	    int regionCount = 1;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < n; j++){
			    if(grid[i][j] == '/'){
				    int topRight = i*pointsPerSide+(j+1);
				    int bottomLeft = (i+1)*pointsPerSide+j;
				    regionCount += union_sets(parents, topRight, bottomLeft);
			    }else if(grid[i][j] == '\\'){
				    int topLeft = i*pointsPerSide + j;
				    int bottomRight = (i+1)*pointsPerSide+(j+1);
				    regionCount += union_sets(parents, topLeft, bottomRight);
			    }
		    }
	    }
	    return regionCount;
    }
    int regionsBySlashes(vector<string>& grid) {
	    return solve2(grid);
	    return solve(grid);
    }
};
