class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
	  bool changed = true;
	  while(changed){
	       changed = false;
	       auto prev = arr;
	       for(int i = 1; i+1<arr.size(); i++){
		       if(prev[i-1] < arr[i] && arr[i+1] < arr[i])arr[i]--, changed=true;
		       if(prev[i-1] > arr[i] && arr[i+1] > arr[i])arr[i]++, changed=true;
	       }
	  }
	  return arr;
    }
};
