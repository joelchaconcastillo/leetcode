class Solution {
public:
    vector<double> solve1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	  unordered_map<string, unordered_map<string, double> > adjMatrix;
	  for(int i = 0 ; i < equations.size(); i++){
		  string from = equations[i][0], to = equations[i][1];
		  adjMatrix[from][to] = values[i];
		  if(from!=to) adjMatrix[to][from] = 1./values[i];
	  }

	  for(auto [node_middle, any1]: adjMatrix){
		  for(auto [node_source,any2]:adjMatrix){
			  for(auto [node_dest, any3]:adjMatrix){
				  if( !adjMatrix.count(node_source) || 
						  !adjMatrix[node_source].count(node_middle)||
						  !adjMatrix.count(node_middle) ||
						  !adjMatrix[node_middle].count(node_dest))continue;
				  if(!adjMatrix.count(node_source) || !adjMatrix[node_source].count(node_dest)){
				      adjMatrix[node_source][node_dest] = adjMatrix[node_source][node_middle]*adjMatrix[node_middle][node_dest];
				  }
				  else {
					  adjMatrix[node_source][node_dest] = min(
						  adjMatrix[node_source][node_dest],
						  adjMatrix[node_source][node_middle]*adjMatrix[node_middle][node_dest]
						  );
				  }
			  }
		  } 
	  }

	  vector<double> res;
	  for(auto query:queries){
		  auto from=query[0], to=query[1];
		  if(adjMatrix.count(from) && adjMatrix[from].count(to)) res.push_back(adjMatrix[from][to]);
		  else res.push_back(-1.0);
	  }
	  return res;

    }
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;
    string find(string x){
	    if(parent[x]!=x){
		    auto prev_parent = parent[x];
		    parent[x] = find(parent[x]);
		    weight[x] *= weight[prev_parent];
	    }
	    return parent[x];
    }
    void unite(string x, string y, double value){
	    if(!parent.count(x)){
		    parent[x] = x;
		    weight[x] = 1.0;
	    }
	    if(!parent.count(y)){
		    parent[y] = y;
		    weight[y] = 1.0;
	    }
	    string rootX = find(x), rootY = find(y);
	    if(rootX != rootY){
		    parent[rootX] = rootY;
		    weight[rootX] = value*weight[y]/weight[x];
	    }
    }
    vector<double> solve2(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	    for(int i = 0 ; i < equations.size(); i++){
		    unite(equations[i][0], equations[i][1], values[i]);
	    }
	    vector<double> res;
	    for(auto &query:queries){
		    auto a = query[0], b = query[1];
		    if(!parent.count(a) || !parent.count(b) || find(a) != find(b)){
			    res.push_back(-1.0);
		    }else res.push_back(weight[a]/weight[b]);
	    }
	    return res;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	    return solve2(equations, values, queries);
    }
};
// a/b = 2
// b/c = 3
//  
//  a/3c = 2
//  a = 6c
//
// a/c = ?
// b/a = ?
// a/e = ?
// a/a = ?
// x/x = ?
