typedef long long int lli;
const lli m = 1e9 + 7;
class Solution {
public:
   lli add(lli a, lli b){
      return ((a % m) + (b % m)) % m;
   }
   lli mul(lli a, lli b){
      return ((a % m) * (b % m)) % m;
   }
   int numDecodings(string s) {
      int n = s.size();
      vector <int> dp(n + 1);
      dp[0] = 1;
      if(s[0] == '0') return 0;
      dp[1] = s[0] == '*' ? 9 : 1;
      for(int i = 2; i <= n; i++){
         char first = s[i - 2];
         char second = s[i - 1];
         if(second == '*'){
            dp[i] = add(dp[i], mul(9, dp[i - 1]));
         }else if(second > '0'){
            dp[i] = dp[i - 1];
         }
         if(first == '*'){
            if(second == '*'){
               dp[i] = add(dp[i], mul(15, dp[i - 2]));
            }else if (second <= '6'){
               dp[i] = add(dp[i], mul(2, dp[i - 2]));
            }else{
               dp[i] = add(dp[i], mul(1, dp[i - 2]));
            }
         }else if(first == '1' || first == '2'){
            if(second == '*'){
               if(first == '1'){
                  dp[i] = add(dp[i], mul(9, dp[i - 2]));
               }else if(first == '2'){
                  dp[i] = add(dp[i], mul(6, dp[i - 2]));
               }
            }else if((first - '0') * 10 + (second - '0') <= 26){
               dp[i] = add(dp[i], dp[i - 2]);
            }
         }
      }
      return dp[n];
   }
};
