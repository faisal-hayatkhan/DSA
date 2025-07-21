class Solution:
    def makeFancyString(self, s: str) -> str:
        t=""
        for i in range(len(s)-2):
            if(s[i]==s[i+1] and s[i]==s[i+2]):
                continue
            else:
                t+=s[i]
        t+=s[-2:]
        return t