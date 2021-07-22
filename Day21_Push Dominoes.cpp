class Solution {
public:
    string pushDominoes(string dominoes) {
       int n=dominoes.length();
       int right[n];
       int left [n];
       
        if(dominoes[0]=='.'){
            right[0]=-1;
        }else if(dominoes[0]=='R'){
            right[0]=0;
        }else {
            right[0]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            if(dominoes[i]=='L'){
                right[i]=INT_MAX;
            }else if(dominoes[i]=='R'){
                right[i]=0;
            }else{
                if(right[i-1]==INT_MAX||right[i-1]==-1){
                    right[i]=-1;
                }else {
                    right[i]=right[i-1]+1;
                }
            }
        }
        
        if(dominoes[n-1]=='.'){
            left[n-1]=-1;
        }else if(dominoes[n-1]=='R'){
            left[n-1]=INT_MAX;
        }else {
            left[n-1]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(dominoes[i]=='L'){
                left[i]=0;
            }else if(dominoes[i]=='R'){
                left[i]=INT_MAX;
            }else {
                if(left[i+1]==INT_MAX||left[i+1]==-1){
                    left[i]=-1;
                }else{
                    left[i]=left[i+1]+1;
                }
            }
        }
      
        string ans="";
        for(int i=0;i<n;i++){
            if(left[i]==-1&&right[i]!=-1){
                ans+="R";
            }
            else if(left[i]!=-1&&right[i]==-1){
                ans+="L";
            }
            else if(left[i]<right[i]){
                ans+="L";
            }else if(left[i]==right[i]){
                ans+=".";
            }else{
                ans+="R";
            }
        }
        return ans;
    }
};
