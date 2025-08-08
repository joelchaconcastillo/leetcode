class Solution {
public:
    void dfs1(int width, vector<int> &bricks, int pos, int mask, vector<int> &masks){
	    if(width==pos){
		    masks.push_back(mask);
		    return;
	    }
	    for(auto brick:bricks){
		    int new_pos = pos+brick;
		    if( width > new_pos)
		    dfs1(width, bricks, new_pos, mask|(1<<new_pos), masks);
		    else if(width==new_pos)
		    dfs1(width, bricks, new_pos, mask, masks);
	    }
    }
    long long MOD = 1e9+7;
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs2(vector<int> &masks, int height, int prev){
	    if(height==0)return 1;
	    if(memo.count(height) && memo[height].count(prev))return memo[height][prev];
	    int res = 0;
	    for(auto mask:masks){
		    if(prev&mask)continue;
		    res = (res+dfs2(masks, height-1, mask))%MOD;
	    }
	    return memo[height][prev] = res;
    }
    int solve(int height, int width, vector<int> &bricks){
	    vector<int> masks;
	    dfs1(width, bricks,0, 0, masks);
	    return dfs2(masks, height, 0);
    }
    int buildWall(int height, int width, vector<int>& bricks) {
	    return solve(height, width, bricks);
    }
};
/*
 
 
 
 * */
