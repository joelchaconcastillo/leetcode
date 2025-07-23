class Solution {
public:
    string solve(string &st){
	    vector<int> stack;
	    int n = st.size();
	    unordered_set<char> marked;
	    unordered_map<char, int> last_idx;
	    for(int i = 0 ; i <n;i++) last_idx[st[i]]=i;
	    for(int i = 0 ; i < n; i++){
		    if(!marked.count(st[i])){
			while(!stack.empty() && 
					st[i] < st[stack.back()] &&
				       	last_idx[st[stack.back()]]>i){
				marked.erase(st[stack.back()]);
				stack.pop_back();
			}
			stack.push_back(i);
			marked.insert(st[i]);
		    }
	    }
	    string res ="";
	    for(auto i:stack)res+=st[i];
	    return res;
    }
    string removeDuplicateLetters(string s) {
	    return solve(s);
    }
};
/*
 Input: s = "cbacdcbc"
           
     acd
             
 Output: "acdb"

 * */
