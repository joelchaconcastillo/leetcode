class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater<int>());
	int res = 0, minv=INT_MAX, j=0;
	int n = boxes.size();
	for(auto w:warehouse){
		minv = min(minv, w);
		while(j < n && boxes[j] > minv)j++;
		if(j<n){
			res++;
			j++;
		}
	}
	return res;
    }
};
