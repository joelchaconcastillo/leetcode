class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string> > data;
	for(auto word:words){
		string dif="";
		for(int i = 0;i+1<word.size(); i++){
			int d = word[i+1]-'a' - (word[i]-'a');
			dif += to_string(d)+"_";
		}
		data[dif].push_back(word);
	}
	for(auto [dif, word_vec]:data){
		if(word_vec.size()==1)return word_vec.front();
	}
	return "";
    }
};
