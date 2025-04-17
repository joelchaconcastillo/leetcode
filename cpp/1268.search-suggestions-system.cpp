class Solution {
public:
    vector<vector<string>> solve(vector<string> &products, string &searchWord){
	 unordered_map<string, priority_queue<string> > rolling;

	 for(auto &product:products){
	     string prefix="";
	     for(auto l:product){
		    prefix +=l;
		    rolling[prefix].push(product);
		    if(rolling[prefix].size()>3) rolling[prefix].pop();
	     }
	 }
	 vector<vector<string> > res;
	 string _prefix = "";
	 for(auto l:searchWord){
		_prefix += l;
		vector<string> row;
		while(!rolling[_prefix].empty()){
		    row.push_back(rolling[_prefix].top());
		    rolling[_prefix].pop();
		}
		reverse(row.begin(), row.end());
		res.push_back(row);
	 }
	 return res;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
	   return solve(products, searchWord);
    }
};
