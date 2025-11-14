class Solution {
public:
    vector<int> r_greater;
    bool helper(vector<int> &preorder, int l, int r){
	    if(l+1>=r)return true;
	    int mid = r_greater[l];
	    if(mid==-1)mid=r;
	    for(int i = mid; i < r; i++) if(preorder[i] < preorder[l])return false;
	    return helper(preorder, l+1, mid) && helper(preorder, mid, r);
    }
    bool verifyPreorder(vector<int>& preorder) {
	    int n = preorder.size();
	    r_greater.assign(n, -1);
	    vector<int> st;
	    for(int i = 0 ; i < n; i++){
		    while(!st.empty() && preorder[st.back()] < preorder[i]){
			    r_greater[st.back()]=i;
			    st.pop_back();
		    }
		    st.push_back(i);
	    }
	    return helper(preorder, 0, preorder.size());
    }
};
