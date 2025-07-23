class Solution {
public:
    string solve(string &st){
	    int n = st.size();
	    unordered_map<char, int> rightmost_idx;
	    for(int i = 0 ; i < n; i++) rightmost_idx[st[i]]=i;
	    unordered_set<char> marked;
	    vector<int> stack;
	    for(int i = 0 ; i < n ;i++){
	         if(!marked.count(st[i])){
			 while(!stack.empty() &&
					 st[i] < st[stack.back()] &&
					 rightmost_idx[st[stack.back()]]>i){ //we can remove it

				 marked.erase(st[stack.back()]);
				 stack.pop_back();
			 }
			 marked.insert(st[i]);
			 stack.push_back(i);
		 }
	    }
	    string res = "";
	    for(auto i:stack)res += st[i];
	    return res;
    }
    string smallestSubsequence(string s) {
	    return solve(s);
    }
};
