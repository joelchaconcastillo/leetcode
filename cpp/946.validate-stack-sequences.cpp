class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	    vector<int> st;
	    if(pushed.size() != popped.size())return false;
	    int n = pushed.size();
	    int i=0, j=0;
	    while(i<n && j <n){
		    if( i < n && pushed[i] != popped[j]){
			    st.push_back(pushed[i]);
			    i++;
		    }
		    else if(i < n && j < n && pushed[i] == popped[j]){
			    st.push_back(pushed[i]);
			    while(!st.empty() && st.back() == popped[j]){
				    st.pop_back();
				    j++;
			    }
			    i++;
		    }
	    }
	    return st.empty();
    }
};
