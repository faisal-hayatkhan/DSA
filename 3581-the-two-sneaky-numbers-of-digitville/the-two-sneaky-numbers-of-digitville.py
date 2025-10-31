class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        d={}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        k=[]
        for key,value in d.items():
            if value>1:
                k.append(key)
        return k