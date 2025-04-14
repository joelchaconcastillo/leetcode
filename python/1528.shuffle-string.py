class Solution:
    def solve(self, s, indices):
        res = ['']*len(s)
        for i in range(len(s)):
            res[indices[i]] = s[i]
        return ''.join(res)

    def restoreString(self, s: str, indices: List[int]) -> str:
        return self.solve(s, indices)
        
