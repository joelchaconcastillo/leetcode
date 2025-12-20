class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        prefix_sum = [0]*(n+2)
        for book in bookings:
            prefix_sum[book[0]]+=book[2]
            prefix_sum[book[1]+1] -= book[2]
        current_sum = 0
        res = []
        for i in range(1, n+1):
            current_sum += prefix_sum[i]
            res.append(current_sum)
        return res
