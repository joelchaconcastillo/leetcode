class Solution {
public:
    int solve(vector<vector<int> > &routes, int source, int target){
	    if(target == source)return 0;
	    unordered_map<int, unordered_set<int> > adjListStopRoutes, adjListRoutes;
	    int n = routes.size();
	    for(int i = 0 ;i < routes.size(); i++){
		for(auto stop:routes[i]) adjListStopRoutes[stop].insert(i);
	    }
	    for(int i = 0 ; i < routes.size(); i++){
		    for(auto stop:routes[i]){
			    for(auto next_route:adjListStopRoutes[stop]){
				    if(i!=next_route)
				    adjListRoutes[i].insert(next_route);
			    }
		    }
	    }
	    queue<tuple<int,int> > q;
	    vector<bool> visited(n, false);
	    for(auto route:adjListStopRoutes[source]){
		    visited[route]=true;
		    q.push({1, route});
	    }
	    vector<bool> target_routes(n, false);
	    for(auto routes:adjListStopRoutes[target]) target_routes[routes]=true;
	    while(!q.empty()){
		    auto [cost, route] = q.front();q.pop();
		    if( target_routes[route])return cost;
		    for(auto _to:adjListRoutes[route]){
			    if(visited[_to])continue;
			    visited[_to]=true;
			    q.push({cost+1, _to});
		    }
	    }
	    return -1;
    }
    int solve_optimized(vector<vector<int> > &routes, int source, int target){
	    if(source == target)return 0;
	    unordered_map<int, vector<int> > stop_to_routes;
	    int n = routes.size();
	    for(int i = 0 ; i < n; i++){
		    for(auto stop:routes[i]) stop_to_routes[stop].push_back(i);
	    }
	    queue<int> q;
	    unordered_set<int> visitedStops;
	    vector<bool> usedRoutes(n, false);
	    q.push(source);
	    visitedStops.insert(source);
	    int buses = 0;
	    while(!q.empty()){ // O(n)
		    int _size = q.size();
		    buses++;
		    for(int i =  0 ; i < _size; i++){
		       auto stop = q.front(); q.pop();
		       for(auto route:stop_to_routes[stop]){
		               if(usedRoutes[route])continue;
		               usedRoutes[route]=true;
		               for(auto next_stop:routes[route]){
		           	    if(next_stop == target) return buses;
				    if(visitedStops.count(next_stop))continue;
				    visitedStops.insert(next_stop);
				    q.push(next_stop);
		               }
		       }
		    }
	    }
	    return -1;

    }
    int solve3(vector<vector<int>>& routes, int source, int target) {
	    if(source == target)return 0;
	    unordered_map<int, vector<int> > stopToRoute;
	    int n = routes.size();
	    for(int i = 0 ;i  < n; i++){
		    for(auto stop:routes[i]) stopToRoute[stop].push_back(i);
	    }
	    queue<int> q;
	    for(auto route:stopToRoute[source])q.push(route);
	    int res = 0;
	    unordered_set<int> route_visited;
	    while(!q.empty()){
		    auto _sz = q.size();
		    res++;
		    while(_sz--){
		        auto route = q.front(); q.pop();
			if(route_visited.count(route))continue;
			route_visited.insert(route);
		        for(auto stop:routes[route]){
				if(stop == target)return res;
		                for(auto to_route:stopToRoute[stop]){
					if(route_visited.count(to_route))continue;
					q.push(to_route);
		                }
		        }
		    }
	    }
	    return -1;
    }






















    int solve4(vector<vector<int>>& routes, int source, int target) {
	    if(source==target)return 0;
	    unordered_map<int, vector<int> > node2route;
	    int n = routes.size();
	    for(int i = 0 ; i < n; i++){
		    for(auto node:routes[i]){
			    node2route[node].push_back(i);
		    }
	    }
	    queue<int> q;
	    for(auto route:node2route[source]) q.push(route);
	    int res = 0;
	    unordered_set<int> visited_node, visited_route;
	    while(!q.empty()){
		    int sz = q.size();
		    res++;
		    while(sz--){
		        auto current_route = q.front(); q.pop();
		        if(visited_route.count(current_route))continue;
			visited_route.insert(current_route);
			for(auto next_node:routes[current_route]){
				if(visited_node.count(next_node))continue;
				if(next_node == target) return res;
				for(auto next_route:node2route[next_node]){
					if(visited_route.count(next_route))continue;
					q.push(next_route);
				}
			}
		    }
	    }
	    return -1;
    }
    int solve5(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
	unordered_map<int, vector<int>> stop2routes;
	for(int i = 0 ;i < routes.size(); i++){
		for(auto stop:routes[i])stop2routes[stop].push_back(i);
	}

	queue<tuple<int, int, int> > q;
	q.push({source, 0, -1});
	unordered_set<int> visited_stops, visited_routes;
	while(!q.empty()){
		auto [stop, jumps, prev_route] = q.front(); q.pop();
		if(visited_stops.count(stop))continue;
		visited_stops.insert(stop);
		if(stop == target) return jumps;
		for(auto next_route: stop2routes[stop]){
			if(visited_routes.count(next_route))continue;
			for(auto next_stop:routes[next_route]){
				if(visited_stops.count(next_stop))continue;
				int next_jump = jumps+ (prev_route != next_route);
				q.push({next_stop, next_jump, next_route});
			}
			visited_routes.insert(next_route);
		}
	}
	return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
	    return solve5(routes, source, target);
	    return solve4(routes, source, target);
	    return solve3(routes, source, target);
	    return solve_optimized(routes, source, target);
	    return solve(routes, source, target);
    }
};
