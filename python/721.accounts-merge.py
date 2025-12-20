class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        adjList = { email:[] for row in accounts for email in row[1:]}
        email2Id = { email:row[0] for row in accounts for email in row[1:]}
        emails = set([email for row in accounts for email in row[1:]])
        groups = {row[0]:[] for row in accounts}

        for row in accounts:
            for email in row[2:]:
                adjList[row[1]].append(email)
                adjList[email].append(row[1])

        visited = set()
        def dfs(node, path):
            if node in visited:
                return
            visited.add(node)
            path.append(node)
            for _next in adjList[node]:
                if _next == node:
                    continue
                dfs(_next, path)

        res = []
        for email in emails:
            if email in visited: 
                continue
            id = email2Id[email]
            path = []
            dfs(email, path)
            path.sort()
            res.append([id]+path)

        return res


