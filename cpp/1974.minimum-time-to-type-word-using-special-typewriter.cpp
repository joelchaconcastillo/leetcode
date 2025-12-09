class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
	char prev = 'a';
	//  bza
	//  1,27,0
	//   a b c
	//   0 1 2
	//   * *
	//   delta = 2
	for(auto letter:word){
		int pos1 = min(prev - 'a', letter-'a');
		int pos2 = max(prev - 'a', letter-'a');
		int delta = pos2-pos1;
		res += min(delta, 26-delta);
		prev = letter;
	}
	res += word.size();
        return res;	
    }
};
