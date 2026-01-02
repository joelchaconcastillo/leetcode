class Solution {
public:

    int largestInteger(int num) {
	    vector<int>even, odd;
	    vector<int> evenIdx, oddIdx;
	    string num_str = to_string(num);
	    int res = num;
	    for(int i = 0 ;i < num_str.size(); i++){
		    int digit = num_str[i]-'0';
		    if(digit%2==0){
			    even.push_back(digit);
			    evenIdx.push_back(i);
		    }
		    else{
			    odd.push_back(digit);
			    oddIdx.push_back(i);
		    }
	    }
	    sort(even.begin(), even.end());
	    reverse(even.begin(), even.end());
	    for(int i = 0 ; i < even.size(); i++){
		    num_str[evenIdx[i]] = even[i]+'0';
	    }
	    sort(odd.begin(), odd.end());
	    reverse(odd.begin(), odd.end());
	    for(int i = 0 ; i < odd.size(); i++){
		    num_str[oddIdx[i]] = odd[i]+'0';
	    }
	    return stoi(num_str);
    }
};
