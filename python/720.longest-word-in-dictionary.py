class Solution:
    def longestWord(self, words: List[str]) -> str:
        prefixes = set(words)
        res = ""
        for word in words:
            current = ""
            for letter in word:
                current += letter
                if current in prefixes:
                    if len(res) < len(current):
                        res = current
                    elif len(res) == len(current):
                        res = min(res, current)
                else:
                    break
        return res

