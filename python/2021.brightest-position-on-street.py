class Solution:
    def brightestPosition(self, lights: List[List[int]]) -> int:
        intervals = sortedcontainers.SortedDict()
        for light in lights:
            l, r = light[0]-light[1], light[0]+light[1]+1
            intervals[l] = intervals.get(l,0)+1
            intervals[r] = intervals.get(r,0)-1
        current = 0
        res = -math.inf
        start = -math.inf
        for key,val in intervals.items():
            current += val
            if res < current:
                res = current
                start = key
            elif res == current:
                start = min(start, key)
        return start
