class Solution {
public:
    int Solve(int num){
	    int maxv = INT_MIN, minv = INT_MAX;
	    for(char old = '0'; old <='9'; old++){
		    for(char _new = '0'; _new <= '9'; _new++){
	                    string current = to_string(num);
			    for(auto &letter:current){
				    if(letter == old) letter = _new;
			    }
		    maxv = max(maxv, stoi(current));
		    minv = min(minv, stoi(current));

		    }
	    }
	    return maxv-minv;
    }
    int minMaxDifference(int num) {
	    return Solve(num);
    }
};
