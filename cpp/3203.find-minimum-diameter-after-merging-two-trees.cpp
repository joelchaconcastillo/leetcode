class Solution {
public:
    vector<vector<int> > to_adj(vector<vector<int> > &edges){
	   vector<vector<int> > adjList(edges.size()+1);//its a tree
	   for(auto edge:edges){
	      adjList[edge[0]].push_back(edge[1]);
	      adjList[edge[1]].push_back(edge[0]);
	   }
	   return adjList;
    }
    int get_diameter(vector<vector<int> > &adjList){
	queue<int> q; //node
        q.push(0);
	int last_node = 0;
	vector<bool> visited(adjList.size(), false);
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
	visited.assign(adjList.size(), false);
	int diameter = 0;
	q2.push({last_node,0});
	while(!q2.empty()){
	     auto [current, dist] = q2.front(); q2.pop();
	     if(visited[current])continue;
	     visited[current]=true;
	     diameter = max(diameter, dist);
	     for(auto _to:adjList[current]){
		     if(visited[_to])continue;
		     q2.push({_to, dist+1});
	     }
	}
	return diameter;
    }
    int solve(vector<vector<int> > &edges1, vector<vector<int> > &edges2){
	auto adjList1 = to_adj(edges1), adjList2 = to_adj(edges2);
	auto D1 = get_diameter(adjList1), D2 = get_diameter(adjList2);
	int new_diameter = ceil(D1/2.0)+ceil(D2/2.0)+1;
	return max({new_diameter, D1, D2});
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
	  return solve(edges1, edges2);
    }
};
