class Solution:
    def minInsertions(self, s: str) -> int:
        memo={}
        def solve(i,j):
            if i>=j:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]
            if s[i]==s[j]:
                return solve(i+1,j-1)
            else:
                memo[(i,j)]=1+min(solve(i+1,j),solve(i,j-1))
            return memo[(i,j)]
        n=len(s)
        return solve(0,n-1)