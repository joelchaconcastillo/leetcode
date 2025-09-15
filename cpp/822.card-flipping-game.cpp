class Solution {
public:

    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int, int> freq;
        for(auto num:fronts)freq[num]++;
        for(auto num:backs)freq[num]++;	
	unordered_set<int>isValid;
	int n = fronts.size();
	for(int i= 0 ; i < n; i++){
		if(fronts[i]==backs[i]) isValid.insert(fronts[i]);
	}
	int res = INT_MAX;
	for(auto [num, cnt]:freq){
		if(isValid.count(num))continue;
		res = min(res, num);
	}
	if(res == INT_MAX)return 0;
	return res;
    }
};
//   1 2 3 4 7
//       i
//
//  Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
//  1,1
//  2,3
//  4,4 
//  4,1
//  7,4
//  Output: 2
