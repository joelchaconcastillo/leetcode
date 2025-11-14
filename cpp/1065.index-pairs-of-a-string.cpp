class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
	    vector<vector<int > > res;
	    for(auto &word:words){
		int index = text.find(word);
		while(index != std::string::npos){
		   int pos = static_cast<int>(index);
		   res.push_back({pos, pos+(int)word.size()-1});
		   index = text.find(word, index+1);
		}
	    }
	    sort(res.begin(), res.end());
	    return res;
    }
};
