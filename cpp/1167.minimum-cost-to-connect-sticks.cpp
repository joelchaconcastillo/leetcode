class Solution {
public:
    int solve(vector<int> &sticks){
	    int n = sticks.size();
	    priority_queue<int, vector<int>, greater<>> pq;
	    for(auto i:sticks)pq.push(i);
	    int res = 0;
	    while(pq.size()>1){
		    int num1 = pq.top();pq.pop();
		    int num2 = pq.top();pq.pop();
		    res +=num1+num2;
		    pq.push(num1+num2);
	    }
	    return res;
    }
    int connectSticks(vector<int>& sticks) {
	    return solve(sticks);
    }
};
