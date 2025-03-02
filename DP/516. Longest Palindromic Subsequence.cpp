class Solution {
    public:
        int dp[1001][1001];
        int solve(int i , int  j ,  string&s )
        {
            if(i>j)
            {
                return 0;
            }
            if(i==j)
            {
                return 1;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            if(s[i]==s[j])
            {
                dp[i][j] =2+solve(i+1 , j-1 , s);
            }
            else
            {
                dp[i][j] = max(solve(i+1 , j ,s) , solve(i , j-1 , s));
            }
            return dp[i][j];
        }
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            memset(dp,-1,sizeof(dp));
            return solve(0 , n-1 , s );
        }
    };

//approach_2

class Solution {
public:
    int dp[1001][1001];
    int solve(int i , int  j , int  m , int  n , string&s , string&t)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s[i]==t[j])
        {
            dp[i][j]=1+solve(i+1, j+1 , m , n , s , t);
        }
        else
        {
            dp[i][j] = max( solve(i+1, j , m , n , s , t) , solve(i, j+1 , m , n , s , t));
        }
        
        return dp[i][j];

    }
    int longestPalindromeSubseq(string s) {
        int m  = s.length();
        string t  = s;
        reverse(t.begin() , t.end());
        int n  = t.length();
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , m , n ,  s , t);
    }
};
