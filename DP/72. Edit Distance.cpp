class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , string&s , string&t , int m , int n)
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
        if(s[i]==t[j])
        {
           dp[i][j]=solve(i+1,j+1,s,t,m,n);
        }
        else
        {
            int insert = 1+solve(i,j+1,s,t,m,n);
            int delet = 1+solve(i+1,j,s,t,m,n);
            int replace = 1+solve(i+1,j+1,s,t,m,n);
            dp[i][j] = min({insert , delet , replace });
        }
       return dp[i][j];
    }
    int minDistance(string word1, string word2) {
      int m = word1.length();
      int n = word2.length();
      memset(dp,-1,sizeof(dp));
      return solve(0 , 0 , word1 , word2 , m , n);
    }
};
