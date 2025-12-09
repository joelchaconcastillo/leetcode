class Solution {
public:
    bool solve1(vector<int>& arr, int start) {
	    int n = arr.size();
	    queue<int> q;
	    q.push(start);
	    arr[start]=-arr[start];
	    while(!q.empty()){
		    auto current = q.front(); q.pop();
		    if(arr[current] == 0)return true;
	            vector<int> next_all = {current+arr[current], current-arr[current]};
		    for(auto next:next_all){
			    if(next<0 || next>=n)continue;
			    if(arr[next]<0)continue;
			    arr[next] = -arr[next];
			    q.push(next);
		    }
	    }
	    return false;
    }
    bool canReach(vector<int>& arr, int start) {
	    return solve1(arr, start);
    }
};
