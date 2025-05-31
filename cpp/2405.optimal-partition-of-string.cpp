class Solution {
public:
    int solve(string &s){
	unordered_set<char> marked;
	int res = 0;
	for(auto letter:s){
	   if(marked.count(letter)){
		 res++;
		 marked.clear();
	   }
	   marked.insert(letter);
	}
	if(!marked.empty())res++;
	return res;
    }
    int partitionString(string s) {
	return solve(s);
    }
};
