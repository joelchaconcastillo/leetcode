class Solution(object):

    def comb(self, _current, n, i, parentesis):
        if i < 0:
            return
        if n == 0:
            if i == 0:
               parentesis.append(_current)
            return

        self.comb(_current+"(", n-1, i+1, parentesis)
        self.comb(_current+")", n-1, i-1, parentesis)

    def solve(self, n):
        parentesis = []
        self.comb("", 2*n, 0, parentesis)
        return parentesis

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return self.solve(n)
