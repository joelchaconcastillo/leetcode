class Solution {
public:
    int getLucky(string s, int k) {
	string res = "";
	for(auto i:s)res += to_string((i-'a'+1));

        for(int i = 0; i < k; i++){
		int sum = 0;
		for(auto j:res) sum += j-'0';
		res = to_string(sum);
	}		
	return stoi(res);
    }
};
