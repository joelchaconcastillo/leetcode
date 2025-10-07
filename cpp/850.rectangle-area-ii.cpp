class Solution {
public:
    int MOD = 1e9+7;
    int solve1(vector<vector<int>>& rectangles) {
	    set<int> x, y;
	    for(auto rectangle:rectangles){
		    x.insert(rectangle[0]);
		    x.insert(rectangle[2]);
		    y.insert(rectangle[1]);
		    y.insert(rectangle[3]);
	    }
	    unordered_map<int, int> invMapX ,invMapY, mapX, mapY;
	    int i = 0;
	    for(auto val:x){
		    invMapX[i]=val;
		    mapX[val]=i;
		    i++;
	    }
	    int j = 0;
	    for(auto val:y){
		    invMapY[j]=val;
		    mapY[val]=j;
		    j++;
	    }
	    vector<vector<int> > area(invMapX.size(), vector<int>(invMapY.size(),0));
	    for(auto rectangle:rectangles){
		    for(int x = mapX[rectangle[0]]; x < mapX[rectangle[2]]; x++){
			    for(int y = mapY[rectangle[1]]; y < mapY[rectangle[3]]; y++){
				    area[x][y]=1;
			    }
		    }
	    }
	    long long res = 0;
	    for(int i = 0 ; i < area.size(); i++){
		    for(int j = 0 ; j < area[0].size(); j++){
			    if(area[i][j])
			    res += (long long)(invMapX[i+1]-invMapX[i])*(invMapY[j+1]-invMapY[j]);
		    }
	    }
	    res %= MOD;
	    return res;
    }
    int solve2(vector<vector<int>>& rectangles) {
	    vector<vector<int> > events;
	    for(auto rectangle:rectangles){
		    events.push_back({rectangle[1], 0, rectangle[0], rectangle[2]});
		    events.push_back({rectangle[3], 1, rectangle[0], rectangle[2]});
	    }
	    sort(events.begin(), events.end());
	    multiset<vector<int>> actives;
	    long long res = 0;
	    int prev_y = events[0][0];
	    for(auto event:events){
		    int y = event[0], action = event[1], x1 = event[2], x2 = event[3];
		    int max_x = -1; long long area_x = 0;
		    for(auto active:actives){
			    max_x = max(max_x, active[0]);
			    area_x += max(active[1]-max_x, 0);
			    max_x = max(max_x, active[1]);
		    }
		    res += area_x*(y-prev_y);
		    if(action==0){
			    actives.insert({x1, x2});
		    }else{
			    auto it = actives.find({x1,x2});
			    actives.erase(it);
		    }
		    prev_y = y;
	    }
	    res %=MOD;
	    return res;
    }
    vector<int> count, x;
    vector<long long> length;
    void update(int node, int l, int r, int ql, int qr, int val){
	    if( qr <= l || ql >=r)return;
	    if(l>=ql && r<=qr){
		    count[node] += val;
	    }else{
	      int mid = (l+r)/2;
	      update(node*2, l, mid, ql, qr, val);
	      update(node*2+1, mid, r, ql, qr, val);
	    }
	    if(count[node] > 0) length[node] = x[r]-x[l];
	    else if(l+1 < r) length[node] = length[node*2]+length[node*2+1];
	    else length[node] = 0;
    }
    int solve3(vector<vector<int>>& rectangles) {
	    vector<vector<int> > events;
	    vector<int>xs;
	    for(auto rectangle:rectangles){
		    events.push_back({rectangle[1],1,rectangle[0],rectangle[2]});
		    events.push_back({rectangle[3],-1,rectangle[0],rectangle[2]});
		    xs.push_back(rectangle[0]);
		    xs.push_back(rectangle[2]);
	    }
	    sort(xs.begin(), xs.end());
	    xs.erase(unique(xs.begin(), xs.end()), xs.end());
	    x = xs;
	    int n = xs.size();
	    sort(events.begin(), events.end());
	    count.assign(4*n, 0);
	    length.assign(4*n, 0);
	    long long res = 0, cur_x_sum=0;
	    int prev_y = 0;
	    for(auto event:events){
		    int y = event[0], action=event[1], x1=event[2], x2=event[3];
		    res += length[1]*(y-prev_y);
		    int l = lower_bound(xs.begin(), xs.end(), x1)-xs.begin();
		    int r = lower_bound(xs.begin(), xs.end(), x2)-xs.begin();
		    update(1, 0, n-1, l, r, action);
		    prev_y = y;
	    }
	    res %=MOD;
	    return res;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
	    return solve3(rectangles);
	    return solve2(rectangles);
	    return solve1(rectangles);
    }
};
