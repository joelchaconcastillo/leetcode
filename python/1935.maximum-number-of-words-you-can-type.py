class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        res = 0
        for word in text.split():
            for letter in word:
                if letter in brokenLetters:
                    res+=1
                    break
        return len(text.split())-res
