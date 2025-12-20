class Solution {
public:
    int solve(vector<int>& boxes, vector<int>& warehouse) {
	    int minv= INT_MAX;
	    int m = boxes.size(), n = warehouse.size();
	    vector<int> wh = warehouse;
	    for(auto &w:wh){
		    minv = min(minv, w);
		    w = minv;
	    }
	    minv = INT_MAX;
	    for(int i = n-1; i>=0; i--){
		    minv = min(minv, warehouse[i]);
		    wh[i] = max(wh[i], minv);
	    }
	    sort(wh.begin(), wh.end());
	    sort(boxes.begin(), boxes.end());
	    int res =0 ;
	    for(int i = 0, j=0; i < n; i++){
		    if( j < m && boxes[j] <= wh[i]){
			    j++;
			    res++;
		    }
	    }
	    return res;
    }
    int solve2(vector<int>& boxes, vector<int>& warehouse) {
	    sort(boxes.begin(), boxes.end());
	    int left =0 , right = warehouse.size()-1;
	    int res = 0, j = boxes.size()-1;
	    while(left<=right && j >=0){
		    if(boxes[j] <= warehouse[left]){
			    res++;
			    left++;
		    }else if(boxes[j]  <= warehouse[right]){
			    res++;
			    right--;
		    }
		    j--;
	    }
	    return res;
    }
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
	return solve2(boxes, warehouse);
	return solve(boxes, warehouse);
    }
};
