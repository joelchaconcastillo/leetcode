class Solution:

    def is_winner(self, dash, t):
        if dash[0][0] == t and dash[1][1] == t and dash[2][2] == t:
            return True
        if dash[2][0] == t and dash[1][1] == t and dash[0][2] == t:
            return True
        for i in range(3):
            if dash[0][i] == t and dash[1][i] == t and dash[2][i] == t:
                return True
            if dash[i][0] == t and dash[i][1] == t and dash[i][2] == t:
                return True
        return False

    def solve(self, moves) -> str:
        dash = [["" for _ in range(3)] for _ in range(3)]
        for i in range(len(moves)):
            if i%2 == 0:
                dash[moves[i][0]][moves[i][1]] = "A"
            else:
                dash[moves[i][0]][moves[i][1]] = "B"
            if self.is_winner(dash, "A"):
                return "A"
            if self.is_winner(dash, "B"):
                return "B"
        if len(moves) < 9:
            return "Pending"
        return "Draw"


    def tictactoe(self, moves: List[List[int]]) -> str:
        return self.solve(moves)
