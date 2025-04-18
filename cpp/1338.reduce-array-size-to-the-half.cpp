class Solution {
public:
    int solve(vector<int> &arr){
	unordered_map<int, int> counter;
        for(auto i: arr)counter[i]++;
        priority_queue<tuple<int, int>>pq;
        for(auto ii:counter)  pq.push({ii.second, ii.first});
        int n = arr.size(), cu_size=n, res=0;
        while(cu_size > n/2){
            auto [rep, val] = pq.top(); pq.pop();
            cu_size -=rep;
            res++;
        }
        return res;
    }
    int minSetSize(vector<int>& arr) {
	return solve(arr);
    }
};
