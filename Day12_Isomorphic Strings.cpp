class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        
        if(n1 != n2)
        {
            return false;
        }
        
        int temp1[256];
        memset(temp1,-1,sizeof(temp1));
        int temp2[256];
        memset(temp2,-1,sizeof(temp2));
        
        for(int i=0;i<n1;i++)
        {
            if(temp1[s[i]] != temp2[t[i]])
            {
                return false;
            }
            
            temp1[s[i]]=i;
            temp2[t[i]]=i;
            
            
        }
        return true;
        
    
        
    }
};
