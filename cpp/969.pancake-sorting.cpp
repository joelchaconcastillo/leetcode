class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
	    int n = arr.size();
	    vector<int> res;
	    for(int i = n-1; i>=0; i--){
		    if(arr[i]!=(i+1)){
			    int idx = 0;
			    for(int j = 0; j < i; j++){
				    if(arr[j] == (i+1)){
					    idx = j;
					    break;
				    }
			    }
			    if(idx != 0){
			      res.push_back(idx+1);
			      reverse(arr.begin(), arr.begin()+idx+1);
			    }
			    res.push_back(i+1);
			    reverse(arr.begin(), arr.begin()+i+1);

		    }
	    }
	    return res;
    }
};
