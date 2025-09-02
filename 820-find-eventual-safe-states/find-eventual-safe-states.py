class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n=len(graph)
        visit=[0]*n
        res=[]

        def dfs(node):
            if visit[node]!=0:
                return visit[node]==2
            visit[node]=1
            for ngh in graph[node]:
                if visit[ngh]==1 or not dfs(ngh):
                    return False
            visit[node]=2
            return True

        for i in range(n):
            if dfs(i):
                res.append(i)
        return res