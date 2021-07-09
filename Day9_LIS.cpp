// O(nlogn) solution

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        const int INF = 1e9;
      vector<int> d(n+1, INF);
      d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
        
    }
};

// O(n^2) solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n];
        dp[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res,dp[i]);
        }
        return res;
    }
};
