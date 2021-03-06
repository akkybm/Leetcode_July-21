class Solution:
    def customSortString(self, order: str, str: str) -> str:
        cnt = Counter(str)
        res = ""
        for c in order:
            if cnt[c]>0:
                res += cnt[c]*c
                del cnt[c]
        for c,v in cnt.items():
            res += v*c
        return res
        
