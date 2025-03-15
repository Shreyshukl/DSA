//top - down
class Solution {
public:
    int dp[1001][1001];
    bool isPallindrome(int i , int j ,string&s)
    {
         if(i>=j)
        {
           return true;
        }
         if(s[i]!=s[j])
        {
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=isPallindrome(i+1 , j-1 , s);
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i ; j<n ; j++)
            {
                if(isPallindrome(i,j,s))
                {
                    count++;   
                }
            }
        }
        return count;
    }
};


//bottom up (using blueprint)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<bool>>t(n ,vector<bool>(n ,false));

        for(int L = 1 ; L<=n ;L++)
        {
            for(int i = 0 ; i+L-1<n ;i++)
            {
                int j = i+L-1;
                //1 length ka h
                 if(i==j)
                {
                    t[i][j] = true;
                }
                 //2 length ka h
                else if(i+1==j)
                {
                    t[i][j] = (s[i]==s[j]);
                }
                else
                {
                    t[i][j] = (s[i]==s[j]&&t[i+1][j-1]);
                }
 // i se leke j tk ki is substring ki value agr true h to vo pal h
                if(t[i][j]==true)
                {
                    count++;
                } 
            }
           
        }
        return count;
        
    }
};
