/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // "[123, [456,[789]]]"
    // " 123, [456,[789]] "
    //
    //   123     
    //" [ 123,  [456,I1] ] "
    //      789
    NestedInteger recursive(string &s, int l, int r){
	if(l>=r)return NestedInteger();
	if( l+2==r && s.substr(l, r-l) == "[]")return NestedInteger();
	bool onlyIntegers = true;
	for(int i = l; i < r; i++) onlyIntegers &= (isdigit(s[i]) || s[i]=='-' || s[i]=='+');
	if(onlyIntegers) return NestedInteger(stoi(s.substr(l, r-l)));
	if(s[l] == '[') l++, r--;
	if(l>r)return NestedInteger();
	vector<tuple<int, int> > positions;
	int prev = l, cont = 0;
	for(int i = l; i < r; i++){
	   if(s[i] == ',' && cont == 0){
	      positions.push_back({prev, i});
	      prev = i+1;
	   }
	   if(s[i] == '[')cont++;
	   if(s[i] == ']')cont--;
	}
	positions.push_back({prev, r});
	NestedInteger res;
	for(auto [_left, _right]:positions){
	    res.add(recursive(s, _left, _right));
	}
	return res;
    }
    NestedInteger solve1(string &s){
	 return recursive(s, 0, s.size());
    }
    // "[123, [456,[789]]]"
    //              l
    //                 i
    //  st--> [ 123
    //             [ 456
    //                  [ 
    NestedInteger solve2(string &s){
	 if( s[0]!='[')return NestedInteger(stoi(s));
	 vector<NestedInteger> st;
	 int n = s.size(), last=0;
	 for(int i = 0 ; i < n ;i++){
	     if(s[i] == '['){
		 st.push_back(NestedInteger());
		 last = i+1;
	     }else if(s[i] == ','){
		 if(i>last){
		   int val = stoi(s.substr(last, i-last));
		   st.back().add(NestedInteger(val));
		 }
		 last = i+1;
	     }else if(s[i] == ']'){
		 auto tmp = st.back();
		 st.pop_back();
		 if(i>last){
		   int val = stoi(s.substr(last, i-last));
		   tmp.add(NestedInteger(val));
		 }
		 if(!st.empty()){
		   st.back().add(tmp);
		 }else return tmp;
		 last = i+1;
	     }
	 }
	 return st.back();
    }
    NestedInteger deserialize(string s) {
	 return solve2(s);
	 return solve1(s);
    }
};
