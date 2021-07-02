class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;   // to store result
        unordered_map<int,int> mp;     // to store elements and their gap;
        queue<int> q;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]] = abs(x-arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(q.size() == k)
            {
                if(mp[arr[i]] < mp[q.front()])
                {
                    q.pop();
                    q.push(arr[i]);
                }
            }
            else{
                q.push(arr[i]);
            }
        }
        while(k--)
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};
