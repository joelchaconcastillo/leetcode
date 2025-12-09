class Solution:
    def minTimeToType(self, word: str) -> int:
        res = 0
        prev = 'a'
        for letter in word:
            pos1 = min( ord(letter), ord(prev))
            pos2 = max( ord(letter), ord(prev))
            delta = pos2-pos1
            res += min(pos2-pos1, 26-pos2+pos1)
            prev = letter
        res += len(word)
        return res
