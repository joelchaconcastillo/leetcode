class Solution {
public:
    bool isPow(string &st){
	    if(st[0]=='0')return false;
	    int num = stoi(st);
	    return __builtin_popcount(num) == 1;
    }
    bool reorderedPowerOf2(int n) {
         //61 --> 111101
	 // 10000
	 string num = to_string(n);
	 sort(num.begin(), num.end());
	 do{
	      if(isPow(num))return true;
	 }while(next_permutation(num.begin(), num.end()));
	 return false;
    }
};
