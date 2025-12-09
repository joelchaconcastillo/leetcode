class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        tmp = s1+" "+s2
        words = tmp.split(' ')
        freq = collections.Counter(words)
        return [word for word,cont in freq.items() if cont == 1]
