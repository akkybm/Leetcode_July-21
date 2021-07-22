class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxx(n);
        int minval = nums[n-1];
        maxx[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            maxx[i] = max(nums[i],maxx[i-1]);
        }
        int ans = n-1;
        for(int i=n-1;i>=1;i--)
        {
            minval = min(minval,nums[i]);
            
            if(minval >= maxx[i-1])
            {
                ans = i;
            }
        }
        return ans;
    }
};
