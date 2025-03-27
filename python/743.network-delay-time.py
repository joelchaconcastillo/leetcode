import heapq
class Solution(object):
    def solve(self, times, n, k):
        graph = {i:[] for i in range(n)}
        for u,v,w in times:
            graph[u-1].append([v-1, w])
        ##dijkstra...
        dist = n*[1000000]
        dist[k-1] = 0
        pq = [[dist[k-1], k-1]] # dist, start
        while len(pq):
            cur_dist, _from = heapq.heappop(pq)
            if cur_dist > dist[_from]:
                continue

            for _to, w in graph[_from]:
                if dist[_from] + w >= dist[_to]:
                    continue
                dist[_to] = dist[_from]+w
                heapq.heappush(pq, [dist[_to], _to])
        if max(dist) == 1000000:
            return -1
        return max(dist)

    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        return self.solve(times, n, k)
