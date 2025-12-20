class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        n,m,k = len(mat1), len(mat2), len(mat2[0])
        res = [ [0]*k for _ in range(n)]
        for i in range(n):
            for j in range(k):
                for l in range(m):
                    res[i][j] += mat1[i][l]*mat2[l][j]
        return res
        
