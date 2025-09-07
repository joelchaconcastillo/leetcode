class Solution {
public:
	//Input: citations = [0,1,3,5,6]
	//                    5 4 3 2 1
	//                    5 3 0 -3 -5
	//                    
	////Output: 3
	///
    int hIndex(vector<int>& citations) {
	int n = citations.size();
	int lo = 0, hi = n; 
	while(lo < hi){
		int mid = (lo+hi)/2;
		if((n-mid)-citations[mid] <=0){
			hi = mid;
		}else lo=mid+1;
	}
	return n-lo;
    }
};
