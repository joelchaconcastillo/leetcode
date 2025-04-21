class Solution {
public:
    string solve(string &st){
	  unordered_map<char, int> freq;
	  for(auto i:st)freq[i]++;
	  vector<pair<int, char>>sorted;
	  for(auto ii:freq)sorted.push_back({ii.second, ii.first});
	  sort(sorted.begin(), sorted.end(), [] (const pair<int, int> &a, const pair<int, int> &b){
			 return a>b;
			  });
	  string res = "";
	  for(auto ii:sorted) while(ii.first--)res+=ii.second;
	  return res;
    }
    string frequencySort(string s) {
       return solve(s);
    }
};
