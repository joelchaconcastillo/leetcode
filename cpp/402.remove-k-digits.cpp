class Solution {
public:
    string solve(string &num, int k){
	    int n = num.size();
	    if(k==n)return "0";
	    vector<int> stack;
	    int l = n-k;
	    for(int i = 0 ;i < n ;i++){
		    int rem = n-i;
		    while(!stack.empty() &&
			    num[i] < num[stack.back()] &&
				    stack.size()+rem > l){
			    stack.pop_back();
		    }
		    stack.push_back(i);
	    }
	    while(stack.size() > l)stack.pop_back();
	    string res = "";
	    for(auto i:stack)res+=num[i];
	    reverse(res.begin(), res.end());
	    while(!res.empty() && res.back() == '0')res.pop_back();
	    reverse(res.begin(), res.end());
	    if(res.empty())return "0";
	    return res;
    }
    string solve2(string &num, int k){
	    string stack="";
	    for(auto letter:num){
		    while(!stack.empty() &&
				    k>0 &&
				    stack.back() > letter){
			    stack.pop_back();
			    k--;
		    }
		    stack.push_back(letter);
	    }
	    while(!stack.empty() && k>0){
		    stack.pop_back();
			    k--;
	    }
	    reverse(stack.begin(), stack.end());
	    while(!stack.empty() && stack.back() == '0') stack.pop_back();
	    reverse(stack.begin(), stack.end());
	    if(stack.empty())return "0";
	    return stack;
    }
    string removeKdigits(string num, int k) {
	    return solve2(num, k);
	    return solve(num, k);
    }
};
