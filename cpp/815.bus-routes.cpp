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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
	    return solve_optimized(routes, source, target);
	    return solve(routes, source, target);
    }
};
