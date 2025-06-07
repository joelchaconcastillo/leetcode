class Solution {
public:
    // brute force
    int dp(vector<int> &boxes, int taken, vector<bool> &visited){
	if(taken == boxes.size()){
	  return 0;
	}
	//get groups
	vector<int> rem;
	for(int i = 0 ; i < boxes.size(); i++){
		if(visited[i])continue;
		rem.push_back(i);
	}
	vector<vector<int>>groups;
	vector<int> tmp;
	for(int i = 0 ; i < rem.size(); i++){
	    if(!tmp.empty() && boxes[tmp.back()] != boxes[rem[i]]){
		groups.push_back(tmp);
		tmp.clear();
	    }
	    tmp.push_back(rem[i]);
	}
	if(!tmp.empty())groups.push_back(tmp);
	int res = INT_MIN;
	for(auto group:groups){
	    for(auto i:group)visited[i]=true;
	    res = max(res, (int)dp(boxes, taken+group.size(), visited)+(int)(group.size()*group.size()));
	    for(auto i:group)visited[i]=false;
	}
	return res;
    }
    int solve(vector<int> &boxes){
	vector<bool> visited(boxes.size(), false);
	return dp(boxes, 0, visited);
    }
    int memo[100][100][100];
    int dfs(vector<int> &boxes, int l, int r, int k){
	//base case
	if(l>r)return 0;
	//merge groups...
	while(r>l && boxes[r] == boxes[r-1]){
	       	r--; 
		k++;
	}
	if(memo[l][r][k] != -1) return memo[l][r][k];
	int res = dfs(boxes, l, r-1, 0)+(k+1)*(k+1);
	//merge with same color
	for(int i = l; i < r; i++){
	    if(boxes[i]==boxes[r]){
	       res = max(res, 
			       dfs(boxes, l, i, k+1)+
			       dfs(boxes, i+1, r-1, 0));
	    }
	}
	return memo[l][r][k] = res;
    }
    int solve1(vector<int> &boxes){
	int n = boxes.size();
	memset(memo, -1, sizeof memo);
	return dfs(boxes, 0, boxes.size()-1, 0);
    }
    int removeBoxes(vector<int>& boxes) {
	return solve1(boxes);
    }
};
