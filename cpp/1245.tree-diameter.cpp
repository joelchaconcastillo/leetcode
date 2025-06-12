class Solution {
public:
    int solve(vector<vector<int> > &edges){
	vector<vector<int> > adjList (edges.size()+1);
	for(auto edge:edges){
	   adjList[edge[0]].push_back(edge[1]);
	   adjList[edge[1]].push_back(edge[0]);
	}
	int last_node = 0;
	queue<int> q;
	q.push(0);
	vector<bool> visited(edges.size()+1, false);
	while(!q.empty()){
	     auto current = q.front(); q.pop();
	     if(visited[current])continue;
	     visited[current] = true;
	     last_node = current;
	     for(auto _to:adjList[current]){
		     if(visited[_to])continue;
		     q.push(_to);
	     }
	}
	queue<tuple<int, int> > q2;
	q2.push({last_node, 0});
	visited.assign(edges.size()+1, false);
	int diameter = 0;
	while(!q2.empty()){
		auto [current, dist] = q2.front(); q2.pop();
		if(visited[current])continue;
		visited[current] = true;
		diameter = dist;
		for(auto _to:adjList[current]){
		    if(visited[_to])continue;
		    q2.push({_to, dist+1});
		}
	}
	return diameter;
    }
    int treeDiameter(vector<vector<int>>& edges) {
	   return solve(edges);
    }
};
