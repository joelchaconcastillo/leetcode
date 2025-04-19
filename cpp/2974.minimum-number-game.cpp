class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> res;
	priority_queue<int> pq;
	for(auto i:nums)pq.push(-i);
	while(!pq.empty()){
	   auto alice = pq.top(); pq.pop();
	   auto bob = pq.top(); pq.pop();
	   res.push_back(-bob);
	   res.push_back(-alice);
	}
	return res;
    }
};
