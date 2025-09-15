class Solution {
public:
    unordered_map<int, pair<int , int> > deltas= {
	    {0, {0,1}},//North
	    {1, {1,0}},//East
	    {2, {0,-1}},//South
	    {3, {-1,0}}//West
    };
    int solve1(vector<int>& commands, vector<vector<int>>& obstacles) {
	    int facing = 0;
	    pair<int, int> pos(0,0);
	    int maxDist = 0;
	    set<pair<int, int>> isObstacle;
	    for(auto obstacle:obstacles){
		    isObstacle.insert({obstacle[0], obstacle[1]});
	    }
	    
	    for(auto command:commands){
		    if(command==-1){
			   facing = (facing+1)%4;//turn right
		    }else if(command==-2){
			   facing = (facing+3)%4;
		    }else{
			  for(int i = 0 ; i < command; i++){
			     pair<int, int> next(
					     pos.first+deltas[facing].first,
					     pos.second+deltas[facing].second
					     );
			     if(isObstacle.count(next))break;//check that next one won't be an obstacle
			     pos = next; //take it
			  }
		    }
		    maxDist = max(maxDist, pos.first*pos.first+pos.second*pos.second);
	    }
	    return maxDist;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	    return solve1(commands, obstacles);
    }
};
