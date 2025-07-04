class Solution {
public:
    bool solve(vector<vector<int> > &rooms){
	    int n = rooms.size();
	    vector<bool> visited(n, false);
	    queue<int> q;
	    q.push(0);
	    int cnt=0;
	    while(!q.empty()){
		    auto idx = q.front(); q.pop();
		    if(visited[idx])continue;
		    visited[idx] = true;
		    cnt++;
		    for(auto _to:rooms[idx]){
			    if(visited[_to])continue;
			    q.push(_to);
		    }
	    }
	    return cnt==n;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
	    return solve(rooms);
    }
};
