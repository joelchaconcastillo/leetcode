class Solution {
public:
    int magicalString(int n) {

	if(n<=3)return 1;
	string st = "122";
	int idx = 2, current = 1, ones=1;
	while(st.size() < n){
		for(int k = 0; k < st[idx]-'0' && st.size() < n; k++){
			st.push_back(current+'0');
			if(current==1)ones++;
		}
		current = 3-current;
		idx++;
	}
	return ones;
    }
};
// 1 2 2 1 1 2 1 2 2 1 2 2 1 1 2 1 1 2 2
//
// 1 2 2 1 1 2 1 2 2
//           i
//
