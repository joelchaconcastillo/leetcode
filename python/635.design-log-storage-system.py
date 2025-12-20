class LogSystem:
    data = None

    def __init__(self):
        self.data = sortedcontainers.SortedList([])

    def put(self, id: int, timestamp: str) -> None:
        self.data.add([timestamp, id])

    def parse_date(self, timestamp: str, gran:str, replace:chr) -> str:
        res = timestamp
        if gran == "Second":
            return res
        pos = 4
        if gran == "Year": 
            pos = 4
        if gran == "Month":
            pos = 7
        if gran == "Day": 
            pos = 10
        if gran == "Hour": 
            pos = 13
        if gran == "Minute": 
            pos = 16
        return res[:pos]+replace+res[pos+1:]

    def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
        start = self.parse_date(start, granularity, chr(ord(':')-1))
        end = self.parse_date(end, granularity, chr(ord(':')+1))
        left_idx = self.data.bisect_left([start, float('-inf')])
        right_idx = self.data.bisect_right([end, float('inf')])
        return [log[1] for log in self.data[left_idx:right_idx]]


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(start,end,granularity) param_2 = obj.retrieve(start,end,granularity)
