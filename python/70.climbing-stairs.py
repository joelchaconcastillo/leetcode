class Solution(object):
    def solve(self, n):
        if n == 0 or n == 1:
            return 1
        dp_A = 1
        dp_B = 2
        for i in range(2, n):
            dp_C = dp_A + dp_B
            dp_A = dp_B
            dp_B = dp_C
        return dp_B

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.solve(n)
        
