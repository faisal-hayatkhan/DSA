from typing import List

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        seen = [False] * 201
        
        max_sum = 0
        has_positive = False
        max_non_positive = -101 

        for num in nums:
            index = num + 100
            
            if not seen[index]:
                seen[index] = True
                
                if num > 0:
                    max_sum += num
                    has_positive = True
                else: 
                    max_non_positive = max(max_non_positive, num)

        return max_sum if has_positive else max_non_positive