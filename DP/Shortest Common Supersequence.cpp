
class Solution {
  public:

    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>t(m+1, vector<int>(n+1));
        
        for(int i = 0 ; i<m+1 ; i++)
        {
            for(int j = 0 ; j<n+1 ; j++)
            {
               
               if(i==0 || j==0)
               {
                   t[i][j]=0;
               }
               else if(s1[i-1] == s2[j-1])
                {
                    t[i][j]  = 1+t[i-1][j-1];
                }
                else 
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
      int LCS =  t[m][n];
      int extra_from_s1 = m-LCS;
      int extra_from_s2 = n-LCS;    
      
      return LCS+extra_from_s1+extra_from_s2;
    }
};









//bottom up
class Solution {
  public:

    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>t(m+1, vector<int>(n+1 , 0));
        
        //if s2 is empty take all characters of s1
        for(int i = 0 ; i<=m ; i++)
        {
            t[i][0] = i;
        }
        for(int j = 0 ; j<=n ; j++)
        {
            t[0][j] = j;
        }
        
        for(int i = 1 ; i<=m ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
               
                if(s1[i-1] == s2[j-1])
                {
                    t[i][j]  = 1+t[i-1][j-1];
                }
                else 
                {
                    t[i][j] = 1+min(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};




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
