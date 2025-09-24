class Solution {
public:
    vector<tuple<int, int> > directions = {
	    {0,-1}, {0,1}, {-1,0}, {1,0}
    };
    tuple<int, int, vector<pair<int, int>>> bfs(int row, int col, vector<vector<int> > &isInfected, vector<vector<bool> > &visited){
	    int n = isInfected.size(), m = isInfected[0].size();
	    queue<tuple<int, int> > q;
	    q.push({row, col});
	    set<pair<int, int> > frontier;
	    int borders=0;
	    vector<pair<int, int> > component;
	    while(!q.empty()){
		    auto [current_row, current_col] = q.front(); q.pop();
		    if(visited[current_row][current_col])continue;
		    visited[current_row][current_col]=true;
		    if(isInfected[current_row][current_col]!=1)continue;
		    component.push_back({current_row, current_col});
		    for(auto [delta_row, delta_col]:directions){
			    int next_row = current_row+delta_row, next_col = current_col+delta_col;
			    if(next_row < 0 || next_row>=n)continue;
			    if(next_col < 0 || next_col>=m)continue;
			    if(isInfected[next_row][next_col] == 0){
				    borders++;
				    frontier.insert({next_row, next_col});
			    }
			    if(isInfected[next_row][next_col] == 1 && !visited[next_row][next_col])
				    q.push({next_row, next_col});
		    }
	    }
	    return {(int)frontier.size(), borders, component};
    }
    tuple<int, vector<pair<int, int> > > largest_unvisited_component(vector<vector<int> > &isInfected){
	int n = isInfected.size(), m = isInfected[0].size();
	int max_size= 0, max_border=0;
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	vector<pair<int, int> > max_component;
	for(int i = 0 ; i <n; i++){
		for(int j =0 ; j < m; j++){
			if(visited[i][j])continue;
			if(isInfected[i][j] != 1)continue;
			auto [frontier_size, border_cnt, component] = bfs(i, j, isInfected, visited);
			if(frontier_size> max_size){
				max_size = frontier_size;
				max_component = component;
				max_border = border_cnt;
			}
		}
	}
	return {max_border, max_component};
    }
    void remove_component(vector<pair<int, int> > &component, vector<vector<int> > &isInfected){
	    for(auto [row, col]:component){
		    isInfected[row][col]=2;
	    }
    }
    void expand_components(vector<vector<int> > &isInfected){
	    int n = isInfected.size(), m = isInfected[0].size();
	    auto copy = isInfected;
	    for(int i = 0 ; i< n; i++){
		    for(int j = 0 ; j < m; j++){
			    if(isInfected[i][j]!=0)continue;
			    if(i>0 && isInfected[i-1][j]==1)copy[i][j]=1;
			    if(j>0 && isInfected[i][j-1]==1)copy[i][j]=1;
			    if(i+1 < n && isInfected[i+1][j]==1)copy[i][j]=1;
			    if(j+1 < m && isInfected[i][j+1]==1)copy[i][j]=1;
		    }
	    }
	    isInfected=copy;
    }
    int containVirus(vector<vector<int>>& isInfected) {
	int n = isInfected.size(), m = isInfected[0].size();
	int res = 0;
	//0: nothing
	//1: active
	//2: contained
	while(true){
		auto [max_border, component] 
			= largest_unvisited_component(isInfected);
		if(max_border==0)break;
		res += max_border;
		remove_component(component, isInfected);
		expand_components(isInfected);
	}
	return res;
    }
};
