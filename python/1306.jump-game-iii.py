class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque()
        q.append(start)
        while len(q):
            current = q.popleft()
            if arr[current] == 0:
                return True
            if arr[current] < 0:
                continue
            arr[current] = -arr[current]
            for _next in [current+arr[current], current-arr[current]]:
                if _next < 0 or _next >= len(arr) or arr[_next] < 0:
                    continue
                q.append(_next)
        return False

