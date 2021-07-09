#O(n^2) solution

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums);
        dp=[0]*n
        dp[0]=1
        for i in range(1,n):
            dp[i]=1
            for j in range(i):
                if nums[i]>nums[j]:
                    if dp[i]<dp[j]+1:
                        dp[i]=dp[j]+1
        
        return max(dp)
        
        
