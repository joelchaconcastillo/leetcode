class Solution {
public:
    struct comp{
	    bool operator()(const int &a, const int &b){
		    int cnta = __builtin_popcount(a);
		    int cntb = __builtin_popcount(b);
		    if(cnta < cntb)return true;
		    else if(cnta > cntb)return false;
		    return a<b;
	    }
    };
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(), arr.end(), comp{});
       return arr;
    }
};
