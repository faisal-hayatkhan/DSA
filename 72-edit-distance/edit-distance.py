class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo={}
        def rec(i,j):
            if i==0:
                return j
            if j==0:
                return i

            if (i,j) in memo:
                return memo[(i,j)]
                
            if word1[i-1]==word2[j-1]:
                memo[(i,j)]=rec(i-1,j-1)
                return memo[(i,j)]
            
            insert=rec(i,j-1)
            delete=rec(i-1,j)
            replace=rec(i-1,j-1)
            
            memo[(i,j)]=1+min(insert, delete, replace)
            return memo[(i,j)]

        return rec(len(word1), len(word2))