class Solution {
public:
    int countOddLetters(int n) {
	unordered_map<char, string> num2word = {
		{'0', "zero"},
		{'1', "one"},
		{'2', "two"},
		{'3', "three"},
		{'4', "four"},
		{'5', "five"},
		{'6', "six"},
		{'7', "seven"},
		{'8', "eight"},
		{'9', "nine"},
	};
	unordered_map<char, int> freq;
	string num = to_string(n);
	for(auto digit:num){
		for(auto letter:num2word[digit]){
			freq[letter]++;
		}
	}
	int res = 0;
	for(auto [num, times]:freq){
		if(times%2==0)continue;
		res++;
	}
	return res;
    }
};
