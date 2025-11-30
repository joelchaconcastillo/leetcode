class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        m = len(p)
        freq_p = collections.Counter(p)
        freq_q = {}
        res = []
        for i in range(len(s)):
            letter = s[i]
            freq_q[letter] = freq_q.get(letter,0)+1
            if freq_p == freq_q:
                res.append(i-m+1)
            if i-m+1 >= 0:
                freq_q[s[i-m+1]]-=1
                if freq_q[s[i-m+1]] == 0:
                    del freq_q[s[i-m+1]]
        return res
