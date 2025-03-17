class Solution {
public:
    // time: O(n)
    // space: O(n)
    // elapsed time to solve: 4 min.
    int solve(vector<int> &type){
	int n = type.size();
	unordered_set<int> types;
	for(auto i:type)types.insert(i);
	return min(n/2, (int)types.size());
    }
    int distributeCandies(vector<int>& candyType) {
	return solve(candyType);
    }
};
