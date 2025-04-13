class Solution(object):

    def solve(self, cost):
        return list(accumulate(cost, min))

    def minCosts(self, cost):
        """
        :type cost: List[int]
        :rtype: List[int]
        """
        return self.solve(cost)
        
