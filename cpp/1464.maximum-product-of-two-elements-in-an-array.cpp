class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
	for(auto i:nums){
	       	pq.push(-i);
		if(pq.size()>2)pq.pop();
	}
	auto a = -pq.top();pq.pop();
	auto b = -pq.top();
	return (a-1)*(b-1);
    }
};
