class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	  unordered_map<string, vector<int> > st2pos;
	  vector<vector<string> > res;
	  int n = strs.size();
	  for(int i = 0 ; i < n; i++){
		  auto cpy = strs[i];
		  sort(cpy.begin(), cpy.end());
		  st2pos[cpy].push_back(i);
	  } 
	  for(auto [_, pos]:st2pos){
		  vector<string> tmp;
		  for(auto idx:pos){
			  tmp.push_back(strs[idx]);
		  }
		  res.push_back(tmp);
	  }
	  return res;
    }
};
