class Solution:
    def solve(self, s:str) -> int:
        freq = Counter(s)
        for i in range(len(s)):
            if freq[s[i]] == 1:
                return i
        return -1

    def firstUniqChar(self, s: str) -> int:
        return self.solve(s)
        
