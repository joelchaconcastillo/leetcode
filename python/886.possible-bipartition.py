class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        adjList = [[] for i in range(n+1)]
        colors = [-1]*(n+1)
        for a,b in dislikes:
            adjList[a].append(b)
            adjList[b].append(a)

        def dfs(node, color):
            if colors[node] != -1:
                return True
            colors[node] = color

            for _next in adjList[node]:
                if colors[node] == colors[_next]:
                    return False

                if not dfs(_next, 1-color):
                    return False
            return True

        for i in range(1,n+1):
            if colors[i] != -1:
                continue
            if not dfs(i, 0):
                return False
        return True

