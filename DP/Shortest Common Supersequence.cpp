//top-down
class Solution {
  public:
   int dp[501][501];
   int solve(int i , int j ,string &s1 , string &s2 , int m , int n)
   {
       if(i>=m)
       {
          return n-j;
       }
         if(j>=n)
       {
          return m-i;
       }
       
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
      
       if(s1[i] == s2[j])
       {
         return dp[i][j] =  1+solve(i+1 , j+1 , s1 ,s2 , m, n);
       }
        return dp[i][j] =  1+min(solve(i+1 , j ,s1 ,s2 , m , n) , solve(i , j+1 ,s1 ,s2 , m , n));
     
   }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, s1,s2 , m , n);
    }
};
