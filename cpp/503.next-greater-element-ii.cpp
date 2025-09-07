class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
	vector<int>res(n, -1), stack;
        for(int i = 0 ; i < 2*n; i++){
		int id = i%n;
		while(!stack.empty() && nums[stack.back()] < nums[id]){
			res[stack.back()] = nums[id];
			stack.pop_back();
		}
		stack.push_back(id);
	}	
	return res;
    }
};
