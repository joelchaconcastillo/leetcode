class Solution {
public:
    int minOperations(vector<string>& logs) {
	vector<string> stack;
        for(auto operation:logs){
		if(operation== "./")continue;
		if(operation == "../"){
			if(!stack.empty())stack.pop_back();
		}else stack.push_back(operation);
	}
	return stack.size();
    }
};
