class Solution {
public:
	// time: O(1)
	// space: O(1)
	// elapsed time to resolve: 4 min.
    int maxContainers(int n, int w, int maxWeight) {
        return min(maxWeight/w, n*n);
    }
};
// n = 2, w = 3, maxWeight = 15
//  max/w
