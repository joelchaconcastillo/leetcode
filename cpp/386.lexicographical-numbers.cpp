class Solution {
public:
    vector<int> lexicalOrder(int n) {
	vector<int>res;
	//n = 13
	int number=1;
	for(int i= 0; i < n; ++i){
		res.push_back(number);//visit it
		if(number*10<=n){
			number*=10;//go down to next level
			continue;
		}
		while(number%10==9 || number>=n){
			number/=10;//go to up level
		}
		number++;

	}
	return res;
    }
};
