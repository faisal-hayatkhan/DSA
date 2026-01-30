class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        def solve(x):
            if x in memo:
                return memo[x]
            temp=1

            for i in range(x+1,n):
                if pairs[x][1]<pairs[i][0]:
                    temp=max(temp,1+solve(i))
            memo[x]=temp
            return temp

        pairs.sort()
        n=len(pairs)
        ans=0
        memo={}
        for i in range(n):
            ans=max(ans,solve(i))
        return ans

