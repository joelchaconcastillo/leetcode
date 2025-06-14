class Solution {
public:
    bool isPalindrome(string &st){
	    int i = 0, j = st.size()-1;
	    while(i<j){
		    if(st[i]!=st[j])return false;
		    i++,j--;
	    }
	    return true;
    }
    vector<vector<int> > solve(vector<string> &words){
	 unordered_map<string, int> wordIndex;
	 vector<vector<int> > res;
	 int n = words.size();
	 for(int i = 0 ; i < n; i++){
		 wordIndex[words[i]]=i;
	 }
	 for(int i = 0 ; i < n ; i++){
	    string current_word = words[i];
	    for(int j = 0 ; j <= current_word.size(); j++){
		    string prefix = current_word.substr(0, j);
		    string suffix = current_word.substr(j);
		    if(isPalindrome(suffix)){
		        string reversed_prefix = prefix;
			reverse(reversed_prefix.begin(), reversed_prefix.end());
			if(wordIndex.count(reversed_prefix) && wordIndex[reversed_prefix]!=i){
				res.push_back({i,wordIndex[reversed_prefix]});
			}
		    }
		    if(j> 0  && isPalindrome(prefix)){
			string reversed_suffix = suffix;
			reverse(reversed_suffix.begin(), reversed_suffix.end());
			if(wordIndex.count(reversed_suffix) && wordIndex[reversed_suffix]!=i){
				res.push_back({wordIndex[reversed_suffix], i});
			}
		    }
	    }
	 }
	 return res;
    }
    bool isPalindrome2(const string &st, int i, int j){
	    while(i<j){
		    if(st[i++]!=st[j--])return false;
	    }
	    return true;
    }
    struct TrieNode{
	    unordered_map<char, TrieNode*> children;
	    int wordIndex = -1;
	    vector<int> palindromeSuffixIndices;
    };
    TrieNode * root;
    void insert(const string &word, int index){
	   auto current = root;
	   for(int i  = word.size()-1 ; i>=0; i--){
		if(isPalindrome2(word, 0, i)) current->palindromeSuffixIndices.push_back(index);
		if(!current->children.count(word[i])) current->children[word[i]] = new TrieNode();
		current = current->children[word[i]];
	   }
	   current->palindromeSuffixIndices.push_back(index);//empty prefix!
	   current->wordIndex = index;
    }
    void search(const vector<string> &words, int index, vector<vector<int>> &res){
	 TrieNode * current = root;
	 auto word = words[index];
	 for(int i = 0 ; i < word.size(); i++){
	     if(current->wordIndex != -1 && current->wordIndex != index && isPalindrome2(word, i, word.size()-1)){
			     res.push_back({index, current->wordIndex});
	     }
	     if(!current->children.count(word[i]))return;
	     current = current->children[word[i]];
	 }
	 for(int j: current->palindromeSuffixIndices){
		 if(j==index)continue;
			 res.push_back({index, j});
	 }
    }
    vector<vector<int> > solve2(vector<string> &words){
	    root = new TrieNode();
	    int n = words.size();
	    for(int i = 0 ; i < n; i++){
		    insert(words[i], i);
	    }
	    vector<vector<int> > result;
	    for(int i = 0 ; i < n; i++){
		search(words, i, result);
	    }
	    return result;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
	    return solve2(words);
	    return solve(words);
    }
};
/*
   ["abcd","dcba","lls","s","sssll"]
     d
     dc
     dcb
     dcba
 * */
