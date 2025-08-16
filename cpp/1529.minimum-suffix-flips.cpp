class Solution {
public:
    int minFlips(string target) {
        int res = 0, n = target.size();
	int j = n-1;
	while(j>= 0 && target[j]=='1')j--;
	res += j<n-1;
	for(;j>=0; --j){
		if(target[j]=='1')res +=2;
		while(j>=0 && target[j]=='1')j--;
	}
	return res;
    }
};

