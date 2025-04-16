from sortedcontainers import SortedSet

class Solution:
    def solve(self, n):
        if n == 1:
            return 1
        min_heap = SortedSet()
        min_heap.add(1)
        res = 1

        for i in range(n):
            res = min_heap.pop(0)
            min_heap.add(res*2)
            min_heap.add(res*3)
            min_heap.add(res*5)

        return res


    def nthUglyNumber(self, n: int) -> int:
        return self.solve(n)
        
