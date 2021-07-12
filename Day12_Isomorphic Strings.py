class Solution:
    def isIsomorphic(self, str1: str, str2: str) -> bool:
        n1 = len(str1)
        n2 = len(str2)
        
        if n1!=n2:
            return False;
            
        temp1 = {}
        temp2 = {}
        
        for i in range(n1):
            if str1[i] in temp1:
                if temp1[str1[i]] != str2[i]:
                    return False
            else:
                temp1[str1[i]]=str2[i]
                    
            if str2[i] in temp2:
                if temp2[str2[i]] != str1[i]:
                    return False
                    
            else:
                temp2[str2[i]] = str1[i]
        
        return True
        
