class Solution(object):

    def solve(self, n, k, row, column):

        dp = [[0.0]*n for _ in range(n)]
        directions = [[2, -1], [2, 1], 
                      [1, -2], [1, 2], 
                      [-1, -2], [-1, 2], 
                      [-2, -1], [-2, 1]]

        dp[row][column]=1.0
        for step in range(k+1):
            total_prob = 0.0
            dp_next = [[0.0]*n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    for move_to in directions:
                        next_row, next_col = i+move_to[0], j+move_to[1]
                        if next_row < 0 or next_row >=n:
                            continue
                        if next_col < 0 or next_col >=n:
                            continue
                        dp_next[next_row][next_col] += dp[i][j]/8.0
                    total_prob += dp[i][j]
            dp = dp_next

        return total_prob


    def knightProbability(self, n, k, row, column):
        """
        :type n: int
        :type k: int
        :type row: int
        :type column: int
        :rtype: float
        """
        return self.solve(n, k, row, column)
        
