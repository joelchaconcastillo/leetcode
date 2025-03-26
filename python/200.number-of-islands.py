from collections import deque
class Solution(object):
    def solve(self, grid):
        n = len(grid)
        m = len(grid[0])
        res = 0
        for i in range(n):
            for j in range(m):
                queue = deque()
                queue.append([i,j])
                if grid[i][j] == "1":
                    res+=1
                while queue:
                    cur_row, cur_col = queue.popleft()
                    grid[cur_row][cur_col] = "0"
                    for delta_row, delta_col in [[1,0], [-1,0], [0,1], [0,-1]]:
                        next_row = delta_row+cur_row
                        next_col = delta_col+cur_col
                        if next_row < 0 or next_row >=n:
                            continue
                        if next_col < 0 or next_col >=m:
                            continue
                        if grid[next_row][next_col] == "0":
                            continue
                        queue.append([next_row, next_col])
        return res


    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        return self.solve(grid)
