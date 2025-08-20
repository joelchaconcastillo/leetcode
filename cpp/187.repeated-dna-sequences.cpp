class Solution {
public:
    vector<string> solve2(string &st){
	    int n = st.size();
	    unordered_map<int, int> freq;
	    // h(i) = s[i]*pow^n + s[i-1]*pow^(n-1)....
	    long long hash = 0, base=30, power = 1, MOD = 1e9+7;
	    unordered_map<char, int> mp = {
		    {'A',0}, {'C',1}, {'T',2}, {'G',3}
	    };
	    for(int i = 0 ; i < 10; i++){
			hash = (hash*base+mp[st[i]])%MOD;
			power = (power*base)%MOD;
	    }
	    freq[hash]=1;
	    vector<string>res;
	    for(int i = 10; i < n; i++){
		    hash = (hash*base)%MOD;
		    hash = ((hash-mp[st[i-10]]*power)%MOD+MOD)%MOD;
		    hash = (hash+mp[st[i]])%MOD;
		    freq[hash]++;
		    if(freq[hash] == 2){
			    res.push_back(st.substr(i-9, 10));
		    }
	    }
	    return res;
    }
    vector<string> solve1(string &s){
        vector<string> res;
	int n = s.size();
	unordered_map<string, int> freq;
	for(int i = 10; i <= n ;i++) freq[s.substr(i-10, 10)]++;
	for(auto [st,cont]:freq) if(cont>1)res.push_back(st);
	return res;
    }
    vector<string> findRepeatedDnaSequences(string s) {
	    return solve2(s);
	    return solve1(s);
    }
};
