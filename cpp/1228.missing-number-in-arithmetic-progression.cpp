class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
	int delta1 = arr[1]-arr[0];
	int delta2 = arr[n-1]-arr[n-2];
	if(delta1 == delta2){
		for(int i = 0; i+1 <n; i++){
			if(arr[i+1]-arr[i] != delta1){
				return arr[i]+delta1;
			}
		}
	}
	if(arr[2]-arr[1] == delta1){
		return arr[n-2]+delta1;
	}
	return arr[0]+delta2;
    }
};
