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
    int dfs1(vector<NestedInteger> &currentList){
	    int maxDepth = 1;
	    for(auto next:currentList){
		    if(!next.isInteger()){
			    maxDepth = max( maxDepth, dfs1(next.getList())+1);
		    }
	    }
	    return maxDepth;
    }
    int dfs2(vector<NestedInteger> &currentList, int depth, int maxDepth){
	    int total = 0;
	    for(auto next:currentList){
		    if(!next.isInteger()){
			    total += dfs2(next.getList(), depth+1, maxDepth);
		    }else{
			    total += (maxDepth-depth+1)*next.getInteger();
		    }
	    }
	    return total;
    }
    int solve(vector<NestedInteger> & nestedList){
	    int maxDepth = dfs1(nestedList);
	    return dfs2(nestedList, 1, maxDepth);
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
	    return solve(nestedList);
    }
};
