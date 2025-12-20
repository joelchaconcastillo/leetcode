class Leaderboard:

    def __init__(self):
        self.player2score = {}
        self.score2Players = sortedcontainers.SortedSet()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId in self.player2score:
            self.score2Players.remove((self.player2score[playerId], playerId))
        self.player2score[playerId] = self.player2score.get(playerId,0)+score
        self.score2Players.add((self.player2score[playerId], playerId))


    def top(self, K: int) -> int:
        K = min(K, len(self.score2Players))
        _sum = 0
        idx = len(self.score2Players)-1
        while K:
            _sum += self.score2Players[idx][0]
            K-=1
            idx-=1
        return _sum
        

    def reset(self, playerId: int) -> None:
        self.score2Players.remove((self.player2score[playerId], playerId))
        del self.player2score[playerId]


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
