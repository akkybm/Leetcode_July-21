class Solution {
public:
    string customSortString(string order, string str) {
        string res;
        unordered_map<char,int> mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        
        for(int i=0;i<order.length();i++)
        {
            if(mp.find(order[i])!= mp.end())
            {
                auto it = mp.find(order[i]);
                while(it->second > 0)
                {
                    res += it->first;
                    it->second--;
                }
                mp.erase(it);
            }
        }
        
        unordered_map<char,int>:: iterator it;
        for(it = mp.begin();it!=mp.end();it++)
        {
            while(it->second >0)
            {
                res += it->first;
                it->second--;
            }
        }
        return res;
    }
};
