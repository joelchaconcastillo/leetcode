class Solution {
public:
    int solve(string &word){
	vector<pair<int, char>> freq(300, {0, '0'});
	for(auto l:word){
		freq[l-'0'].first++;
		freq[l-'0'].second=l;
	}
	sort(freq.begin(), freq.end(),[](const pair<int, char> &a, const pair<int, char> &b){
			return a > b;
			});
	int res = 0;
	for(int i = 0 ; i < freq.size(); i++){
	   res += freq[i].first*(i/8+1);
	   if(freq[i].first == 0)break;
	}
	return res;
    }
    int minimumPushes(string word) {
	return solve(word);
    }
};
/*
 Input: word = "aabbccddeeffgghhiiiiii"
a:2
b:2
c:2
d:2  1
e:2  1
f:2  1
g:2  1
h:2  1
i:6  1
 Output: 24
 * */
