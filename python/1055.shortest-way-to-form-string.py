class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        current = [-1]*300
        _next = []
        n, m = len(source), len(target)
        for i in range(n-1,-1,-1):
            current[ord(source[i])]=i
            _next.append(current.copy())
        _next.reverse()
        j = 0
        res = 1
        for letter in target:
            if _next[0][ord(letter)] == -1:
                return -1;
            if j == n or _next[j][ord(letter)] == -1:
                res += 1
                j = 0
            j = _next[j][ord(letter)]+1
        return res
