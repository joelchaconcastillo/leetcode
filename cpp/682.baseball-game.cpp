class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        int n = operations.size();
        for(int i = 0 ; i < n ;i++){
		if(operations[i]=="+" && stack.size()>=2){
			stack.push_back(stack[stack.size()-1]+stack[stack.size()-2]);
		}else if(operations[i] == "D")
			stack.push_back(stack.back()*2);
		else if(operations[i]== "C") stack.pop_back();
		else{
			stack.push_back(stoi(operations[i]));
		}
	}	
	int res = 0;
	for(auto i:stack)res+=i;
	return res;
    }
};
