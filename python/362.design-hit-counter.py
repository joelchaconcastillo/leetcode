class HitCounter:
    def __init__(self):
        self.hits = collections.deque()
        self.count = 0

    def hit(self, timestamp: int) -> None:
        self.count+=1
        if len(self.hits) == 0:
            self.hits.append([timestamp, 1])
            return
        if self.hits[-1][0] == timestamp:
            self.hits[-1][1] +=1
            return
        self.hits.append([timestamp, 1])

    def getHits(self, timestamp: int) -> int:
        while len(self.hits) > 0 and timestamp-self.hits[0][0] >= 300:
            self.count -= self.hits[0][1]
            self.hits.popleft()
        return self.count

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
