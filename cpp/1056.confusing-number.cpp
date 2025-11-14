class Solution {
public:

    bool confusingNumber(int n) {
	    string num = to_string(n);
	    unordered_map<char, char> inverse = {
		    {'0','0'},
		    {'1','1'},
		    {'6','9'},
		    {'8','8'},
		    {'9','6'}
	    };
	    string res = "";
	    for(auto digit:num){
		    if(inverse.count(digit)==0)return false;
		    res += inverse[digit];
	    }
	    reverse(res.begin(), res.end());
	    return res != num;
    }
};
