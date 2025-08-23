class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n!=m)return false;
	vector<int> mismatches;
	unordered_map<char, int> freq;
	int max_freq=0;
        for(int i = 0; i < n ;i++){
		if(s[i] != goal[i])mismatches.push_back(i);
		freq[s[i]]++;
		max_freq = max(max_freq, freq[s[i]]);
	}
	if(mismatches.size() == 0){
		if(max_freq >= 2)return true;
		return false;
	}else if(mismatches.size()==1){
		return false;
	}
	else{
          swap(s[mismatches[0]], s[mismatches[1]]);
	}
	return s==goal;
    }
};
