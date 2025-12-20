# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        pivot = 0
        for i in range(n):
            if knows(pivot, i):
                pivot = i
        for i in range(n):
            if i == pivot:
                continue
            if knows(pivot, i):
                return -1
            if not knows(i, pivot):
                return -1
        return pivot
