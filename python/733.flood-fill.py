from collections import deque

class Solution(object):
    def solve(self, image, sr, sc, color):
        nrow = len(image)
        ncol = len(image[0])
        if image[sr][sc] == color:
            return image
        queue = deque()
        queue.append([sr, sc])
        current_color = image[sr][sc]
        while queue:
            row, col = queue.popleft()
            image[row][col] = color
            for delta_row, delta_col in [[-1,0], [1,0], [0,1], [0,-1]]:
                next_row = row+delta_row
                next_col = col+delta_col
                if next_row < 0 or next_row >=nrow:
                    continue
                if next_col < 0 or next_col >=ncol:
                    continue
                if image[next_row][next_col] != current_color:
                    continue
                queue.append([next_row, next_col])
        return image



    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        return self.solve(image, sr, sc, color)
