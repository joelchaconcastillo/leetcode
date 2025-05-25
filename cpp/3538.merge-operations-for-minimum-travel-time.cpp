class Solution {
public:
    #define INT_MAX 10000000 //TODO: problem dependent
    map<tuple<int, int, int, int>, int>memo;
    int dp1(int i, int k, int n, vector<int> &position, vector<int> &time, int prev_pos, int last_time){
	if(k==0 && i==n)return 0;
	if(k < 0) return INT_MAX;
	if(i == n) return INT_MAX;
	tuple<int, int, int, int> key(i, k, prev_pos, last_time);
	if(memo.count(key))return memo[key];
	int res = INT_MAX;
	//merge it
	if(i>0 && i+1<n){
	  time[i+1] += time[i];
	  res = dp1(i+1, k-1, n, position, time, prev_pos, last_time);
	  time[i+1] -= time[i];
	}
	//not merge it
	int dist_seg = position[i] - prev_pos;
	int score = dist_seg*last_time;
	res = min(res, dp1(i+1, k, n, position, time, position[i], time[i])+score);
	return memo[key] = res;
    }
    int solve(int l, int n, int k, vector<int> &position, vector<int> &time){
	memo.clear();
	return dp1(0, k, n, position, time, 0, time.front());
    }
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
	return solve(l, n, k, position, time);
    }
};
