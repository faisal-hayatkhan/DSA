class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        def solve(i):
            if i>max_val:
                return 0
            if i in memo:
                return memo[i]
            skip=solve(i+1)
            take=freq[i]+solve(i+2)
            memo[i] = max(skip, take)
            return max(skip,take)
        if not nums:
            return 0
        n=len(nums)
        max_val=max(nums)
        freq=[0]*(max_val+1)
        for num in nums:
            freq[num]+=num
        memo = {}
        return solve(1)
