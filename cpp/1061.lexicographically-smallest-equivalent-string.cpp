class Solution {
public:
    unordered_map<char, char> parent;
    char _find(char a){
	    return parent[a]==a? a:(parent[a] = _find(parent[a]));
    }
    void _union(char a, char b){
	    a = _find(a), b = _find(b);
	    if( a > b) swap(a,b);
	    parent[b]=a;
    }
    string solve(string &s1, string &s2, string &base){
           for(char i = 'a'; i<='z'; i++) parent[i]=i;
           for(int i =0 ; i <s1.size(); i++){
	       _union(s1[i], s2[i]);
	   }
	   string res ="";
	   for(auto letter:base){
	        res += _find(letter);
	   }
	   return res;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
    return solve(s1,s2,baseStr);
    }
};
